/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:56:47 by zernest           #+#    #+#             */
/*   Updated: 2024/12/16 22:03:22 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_to_win(t_mlx *mlx, char	**map, int e_state)
{
	int	row;
	int	col;

	row = -1;
	while (map[++row])
	{
		col = -1;
		while (map[row][++col])
		{
			if (map[row][col] == '1')
				render (mlx, mlx->sprites->wall, col, row);
			else if (map[row][col] == '0')
				render (mlx, mlx->sprites->floor, col, row);
			else if (map[row][col] == 'C')
				render (mlx, mlx->sprites->item, col, row);
			else if (map[row][col] == 'E' && e_state == 0)
				render (mlx, mlx->sprites->exit_close, col, row);
			else if (map[row][col] == 'E' && e_state == 1)
				render (mlx, mlx->sprites->exit_open, col, row);
			else if (map[row][col] == 'P')
				render (mlx, mlx->sprites->player, col, row);
			else if (map[row][col] == 'X')
				render(mlx, mlx->sprites->enemy, col, row);
		}
	}
}

void	render(t_mlx *mlx, void *img, int wid, int hgt)
{
	mlx_put_image_to_window(mlx->mlx_ptr,
		mlx->win_ptr,
		img,
		wid * SIZE,
		hgt * SIZE);
}
