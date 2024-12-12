/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:17:16 by zernest           #+#    #+#             */
/*   Updated: 2024/12/12 17:16:58 by zernest          ###   ########.fr       */
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
	static int	step_count = 0;

	player_loc = malloc(sizeof(int) * 2);
	if (!player_loc)
		exit_err_str(&mlx, "Failed to take in inputs\n");
	player_loc[0] = 0;
	player_loc[1] = 0;
	escape_key(mlx, key, &player_loc);
	if (key == KEY_UP || key == KEY_W)
		move_up(mlx, &player_loc, &step_count);
	else if (key == KEY_DOWN || key == KEY_S)
		move_down(mlx, &player_loc, &step_count);
	else if (key == KEY_LEFT || key == KEY_A)
		move_left(mlx, &player_loc, &step_count);
	else if (key == KEY_RIGHT || key == KEY_D)
		move_right(mlx, &player_loc, &step_count);
	else
		return (0);
	step_counter(mlx, step_count);
	ft_printf("Steps taken: %i\n", step_count);
	return (0);
}

void	step_counter(t_mlx *mlx, int step_count)
{
	char	*step;

	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		12, 16, 0x00FFFFFF, "Steps: ");
	step = ft_itoa(step_count);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		50, 16, 0x00FFFFFF, step);
	free(step);
}
