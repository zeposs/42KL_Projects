/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:17:16 by zernest           #+#    #+#             */
/*   Updated: 2024/12/11 22:16:13 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	escape(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free_mlx(&mlx);
	exit(0);
	return (0);
}

void	escape_key(t_mlx *mlx, int keycode, int **player_loc)
{
	if (keycode == KEY_ESC)
	{
		free(*player_loc);
		escape(mlx);
	}
	else
		return ;
}

int	controls(int key, t_mlx *mlx)
{
	int			*player_loc;
	static int	move_count = 0;

	player_loc = malloc(sizeof(int) * 2);
	if (!player_loc)
		exit_err_str(&mlx, "Failed to take in inputs\n");
	player_loc[0] = 0;
	player_loc[1] = 0;
	escape_key(key, mlx, &)
}
// finish this function up ^