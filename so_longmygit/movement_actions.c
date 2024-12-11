/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:39:21 by zernest           #+#    #+#             */
/*   Updated: 2024/12/11 20:15:02 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_movement_validity(t_mlx *mlx, int **player_loc, char **map_dup)
{
	int	act_code;

	act_code = valid_movement(map_dup, (*player_loc)[0] - 1, (*player_loc)[1]);
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
	act_code = check_movement_validity(mlx, player_loc, map_dup);
	if (act_code == 0)
		return ;
	(*move_count)++;
	mlx->ex_state = act_code;
	map_dup[(*player_loc)[0] - 1][(*player_loc)[1]] = 'P';
	map_dup[(*player_loc)[0]][(*player_loc)[1]] = '0';
	if (act_code == EXIT_OPEN)
		write_img_to_win(mlx, map_dup, 1);
	else
		write_img_to_win(mlx, map_dup, 0);
}

void	move_down(t_mlx *mlx, int **player_loc, int *move_count)
{
	char	**map_dup;
	int		act_code;

	map_dup = mlx->map_data->map;
	find_player(mlx, player_loc);
	act_code = check_movement_validity(mlx, player_loc, map_dup);
	if (act_code == 0)
		return ;
	(*move_count)++;
	mlx->ex_state = act_code;
	map_dup[(*player_loc)[0] + 1][(*player_loc)[1]] = 'P';
	map_dup[(*player_loc)[0]][(*player_loc)[1]] = '0';
	if (act_code == EXIT_OPEN)
		write_img_to_win(mlx, map_dup, 1);
	else
		write_img_to_win(mlx, map_dup, 0);
}

void	move_left(t_mlx *mlx, int **player_loc, int *move_count)
{
	char	**map_dup;
	int		act_code;

	map_dup = mlx->map_data->map;
	find_player(mlx, player_loc);
	act_code = check_movement_validity(mlx, player_loc, map_dup);
	if (act_code == 0)
		return ;
	(*move_count)++;
	mlx->ex_state = act_code;
	map_dup[(*player_loc)[0]][(*player_loc)[1] - 1] = 'P';
	map_dup[(*player_loc)[0]][(*player_loc)[1]] = '0';
	if (act_code == EXIT_OPEN)
		write_img_to_win(mlx, map_dup, 1);
	else
		write_img_to_win(mlx, map_dup, 0);
}

void	move_right(t_mlx *mlx, int **player_loc, int *move_count)
{
	char	**map_dup;
	int		act_code;

	map_dup = mlx->map_data->map;
	find_player(mlx, player_loc);
	act_code = check_movement_validity(mlx, player_loc, map_dup);
	if (act_code == 0)
		return ;
	(*move_count)++;
	mlx->ex_state = act_code;
	map_dup[(*player_loc)[0]][(*player_loc)[1] + 1] = 'P';
	map_dup[(*player_loc)[0]][(*player_loc)[1]] = '0';
	if (act_code == EXIT_OPEN)
		write_img_to_win(mlx, map_dup, 1);
	else
		write_img_to_win(mlx, map_dup, 0);
}
