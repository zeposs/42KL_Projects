/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:39:21 by zernest           #+#    #+#             */
/*   Updated: 2024/12/16 22:05:26 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_movement_validity(t_mlx *mlx, int **player_loc, char **map_dup,
		int dir)
{
	int	act_code;

	if (dir == 1)
		act_code = movement_check(map_dup, (*player_loc)[0] - 1,
				(*player_loc)[1]);
	else if (dir == 2)
		act_code = movement_check(map_dup, (*player_loc)[0] + 1,
				(*player_loc)[1]);
	else if (dir == 3)
		act_code = movement_check(map_dup, (*player_loc)[0], (*player_loc)[1]
				- 1);
	else
		act_code = movement_check(map_dup, (*player_loc)[0], (*player_loc)[1]
				+ 1);
	if (act_code == 0)
		return (0);
	if (act_code == WIN)
	{
		quit_game(mlx, act_code);
		return (act_code);
	}
	return (act_code);
}

void	move_up(t_mlx *mlx, int **player_loc, int *move_count)
{
	char	**map_dup;
	int		act_code;

	map_dup = mlx->map_data->map;
	find_player(mlx, player_loc);
	act_code = check_movement_validity(mlx, player_loc, map_dup, 1);
	if (act_code == 0)
		return ;
	(*move_count)++;
	mlx->ex_state = act_code;
	map_dup[(*player_loc)[0] - 1][(*player_loc)[1]] = 'P';
	map_dup[(*player_loc)[0]][(*player_loc)[1]] = '0';
	if (act_code == EXIT_OPEN)
		img_to_win(mlx, map_dup, 1);
	else
		img_to_win(mlx, map_dup, 0);
}

void	move_down(t_mlx *mlx, int **player_loc, int *move_count)
{
	char	**map_dup;
	int		act_code;

	map_dup = mlx->map_data->map;
	find_player(mlx, player_loc);
	act_code = check_movement_validity(mlx, player_loc, map_dup, 2);
	if (act_code == 0)
		return ;
	(*move_count)++;
	mlx->ex_state = act_code;
	map_dup[(*player_loc)[0] + 1][(*player_loc)[1]] = 'P';
	map_dup[(*player_loc)[0]][(*player_loc)[1]] = '0';
	if (act_code == EXIT_OPEN)
		img_to_win(mlx, map_dup, 1);
	else
		img_to_win(mlx, map_dup, 0);
}

void	move_left(t_mlx *mlx, int **player_loc, int *move_count)
{
	char	**map_dup;
	int		act_code;

	map_dup = mlx->map_data->map;
	find_player(mlx, player_loc);
	act_code = check_movement_validity(mlx, player_loc, map_dup, 3);
	if (act_code == 0)
		return ;
	(*move_count)++;
	mlx->ex_state = act_code;
	map_dup[(*player_loc)[0]][(*player_loc)[1] - 1] = 'P';
	map_dup[(*player_loc)[0]][(*player_loc)[1]] = '0';
	if (act_code == EXIT_OPEN)
		img_to_win(mlx, map_dup, 1);
	else
		img_to_win(mlx, map_dup, 0);
}

void	move_right(t_mlx *mlx, int **player_loc, int *move_count)
{
	char	**map_dup;
	int		act_code;

	map_dup = mlx->map_data->map;
	find_player(mlx, player_loc);
	act_code = check_movement_validity(mlx, player_loc, map_dup, 4);
	if (act_code == 0)
		return ;
	(*move_count)++;
	mlx->ex_state = act_code;
	map_dup[(*player_loc)[0]][(*player_loc)[1] + 1] = 'P';
	map_dup[(*player_loc)[0]][(*player_loc)[1]] = '0';
	if (act_code == EXIT_OPEN)
		img_to_win(mlx, map_dup, 1);
	else
		img_to_win(mlx, map_dup, 0);
}
