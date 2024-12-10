/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 00:41:12 by zernest           #+#    #+#             */
/*   Updated: 2024/12/10 21:32:41 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**dup_map(t_mlx *mlx)
{
	char	**map_dup;
	char	**map_sample;
	int		row;

	map_dup = malloc(sizeof(char *) * (mlx->win_y + 1));
	if (map_dup == NULL)
		exit_err_str(&mlx, "Failed to clone map for flood fill\n");
	map_sample = mlx->map_data->map;
	row = -1;
	while (map_sample[++row])
		map_dup[row] = ft_strdup(map_sample[row]);
	map_dup[row] = NULL;
	return (map_dup);
}

void	flood_fill(t_mlx **mlx)
{
	int		*player_loc;
	char	**map_dup;

	map_dup = dup_map(*mlx);
	player_loc = malloc(sizeof(int) * 2);
	(*mlx)->ex_state = 0;
	if (!player_loc)
	{
		free_data(&map_dup, &player_loc);
		exit_err_str(mlx, "Flood fill failed\n");
	}
	find_player(*mlx, &player_loc);
	fill(&map_dup, player_loc[0], player_loc[1], mlx);
	if (remaining_c(map_dup) != 0 || (*mlx)->ex_state == 0)
	{
		free_data(&map_dup, &player_loc);
		exit_err_str(mlx, "Error: Invalid Map");
	}
	free_data(&map_dup, &player_loc);
}

void	fill(t_mlx **mlx, char ***map_dup, int row, int col)
{
	int	size_x;
	int	size_y;

	size_x = (*mlx)->win_x;
	size_y = (*mlx)->win_y;
	if (row < 0 || row >= size_y || col < 0 || col >= size_y)
		return ;
	if ((*map_dup)[row][col] == '1' || (*map_dup)[row][col] == 'F')
		return ;
	if ((*map_dup)[row][col] == 'X')
		return ;
	if ((*map_dup)[row][col] == 'E' && remaining_c(*map_dup) == 0)
	{
		(*mlx)->ex_state = 1;
		return ;
	}
	else if ((*map_dup)[row][col] == 'E' && remaining_c(*map_dup) != 0)
		return ;
	(*map_dup)[row][col] = 'F';
	fill(mlx, map_dup, row + 1, col);
	fill(mlx, map_dup, row - 1, col);
	fill(mlx, map_dup, row, col + 1);
	fill(mlx, map_dup, row, col - 1);
}
