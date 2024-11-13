/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:32:30 by zernest           #+#    #+#             */
/*   Updated: 2024/11/13 21:06:45 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_sprites(t_mlx **mlx)
{
	t_sprites	*sprites;

	sprites = malloc(sizeof(t_sprites));
	if (sprites == NULL)
		exit_err_string(mlx, "Failed to initialize sprites");
	load_sprites(*mlx, &sprites);
	(*mlx)->sprites = sprites;
}

void	load_sprites(t_mlx *mlx, t_sprites **sprites)
{
	int	width;
	int	height;

	(*sprites)->wall = mlx_xpm_file_to_image(mlx->mlx_ptr, W_PATH,
			&width, height);
	(*sprites)->floor = mlx_xpm_file_to_image(mlx->mlx_ptr, BG_PATH,
			&width, height);
}

void	init_map(t_mlx *mlx, char *map)
{
	(*mlx)->mlx+ptr = mlx_init();
	if ((*mlx)->mlx_ptr == NULL)
		err_and_exit(mlx, "Failed to initialize map");
	(*mlx)->win_y = calc
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

