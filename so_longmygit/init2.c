/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 03:31:02 by zernest           #+#    #+#             */
/*   Updated: 2024/12/12 17:06:07 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(int ac, char **av, t_mlx **mlx)
{
	int	fd;

	if (ac != 2)
		ft_putstr_err_exit("Enter map file location\n");
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
		ft_putstr_err_exit("Error opening map file\n");
	(*mlx) = malloc(sizeof(t_mlx));
	if ((*mlx) == NULL)
		ft_putstr_err_exit("Failed to malloc mlx struct\n");
	(*mlx)->sprites = NULL;
	(*mlx)->map_data = NULL;
}

void	init_win(t_mlx **mlx)
{
	flood_fill(mlx);
	(*mlx)->win_ptr = mlx_new_window((*mlx)->mlx_ptr,
			(*mlx)->win_x * SIZE,
			(*mlx)->win_y * SIZE,
			"so_long");
	if ((*mlx)->win_ptr == NULL)
		exit_err_str(mlx, "Failed to initialize window\n");
	init_key(mlx);
}

void	init_key(t_mlx **mlx)
{
	mlx_hook((*mlx)->win_ptr, 2, 1L << 0, controls, *mlx);
	mlx_hook((*mlx)->win_ptr, 17, 0, escape, *mlx);
}

void	gameplay(t_mlx **mlx)
{
	init_win(mlx);
	init_sprites(mlx);
	img_to_win(*mlx, (*mlx)->map_data->map, 0);
}
