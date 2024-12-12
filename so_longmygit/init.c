/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:32:30 by zernest           #+#    #+#             */
/*   Updated: 2024/12/12 19:13:13 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprites(t_mlx **mlx)
{
	t_sprites	*sprites;

	sprites = malloc(sizeof(t_sprites));
	if (sprites == NULL)
		exit_err_str(mlx, "Failed to initialize sprites");
	load_sprites(*mlx, &sprites);
	(*mlx)->sprites = sprites;
}

void	load_sprites(t_mlx *mlx, t_sprites **sprites)
{
	int	width;
	int	height;

	(*sprites)->wall = mlx_xpm_file_to_image(mlx->mlx_ptr, W_PATH,
			&width, &height);
	(*sprites)->floor = mlx_xpm_file_to_image(mlx->mlx_ptr, BG_PATH,
			&width, &height);
	(*sprites)->exit_close = mlx_xpm_file_to_image(mlx->mlx_ptr, BG_PATH,
			&width, &height);
	(*sprites)->exit_open = mlx_xpm_file_to_image(mlx->mlx_ptr, BG_PATH,
			&width, &height);
	(*sprites)->player = mlx_xpm_file_to_image(mlx->mlx_ptr, BG_PATH,
			&width, &height);
}

void	init_map(t_mlx **mlx, char *map)
{
	(*mlx)->mlx_ptr = mlx_init();
	if ((*mlx)->mlx_ptr == NULL)
		exit_perr_string(mlx, "Failed to initialize map");
	(*mlx)->win_y = calc_row(map);
	printf("%d\n", (*mlx)->win_y);
	if ((*mlx)->win_y < 1)
		exit_perr_string(mlx, "Failed to initialize map");
	map_data(mlx, map, (*mlx)->win_y);
	printf("%d\n", (*mlx)->win_y);
	if (!map_check(mlx, (*mlx)->win_y))
		exit_err_str(mlx, "Your map is broken lol");
}

void	map_data(t_mlx **mlx, char *map_location, int size_y)
{
	t_map	*data;

	data = malloc(sizeof(t_map));
	if (data == NULL)
		exit_err_str(mlx, "Failed to allocate memory for map data");
	data->map = read_map(map_location, size_y);
	(*mlx)->win_x = calc_col(data->map, (*mlx)->win_y);
	if ((*mlx)->win_x <= 0)
		exit_err_str(mlx, "win_x less or equal to 0");
	data->player_count = 0;
	data->item_count = 0;
	data->exit_count = 0;
	(*mlx)->map_data = data;
}

char	**read_map(char *map, int size_y)
{
	int		fd;
	int		row;
	char	*line;
	char	**full_map;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (NULL);
	full_map = malloc(sizeof(char *) * (size_y + 1));
	row = -1;
	while (++row < size_y)
	{
		line = get_next_line(fd);
		full_map[row] = ft_strtrim(line, "\n\t\r");
		free(line);
	}
	full_map[size_y] = NULL;
	return (full_map);
}

