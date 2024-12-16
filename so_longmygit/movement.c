/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:45:53 by zernest           #+#    #+#             */
/*   Updated: 2024/12/16 21:26:15 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	movement_check(char **map, int row, int col)
{
	int	c_count;

	c_count = remaining_c(map);
	if (map[row][col] == '1')
		return (0);
	if (map[row][col] == 'C' && c_count == 1)
		return (EXIT_OPEN);
	if (map[row][col] == 'E' && c_count != 0)
		return (0);
	if (map[row][col] == 'E' && c_count == 0)
		return (WIN);
	if (c_count == 0)
		return (EXIT_OPEN);
	return (1);
}

int	remaining_c(char **map)
{
	int	row;
	int	col;
	int	c_count;

	row = 0;
	c_count = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] == 'C')
				c_count++;
			col++;
		}
		row++;
	}
	return (c_count);
}

void	find_player(t_mlx *mlx, int **player_loc)
{
	char	**map;
	int		row;
	int		col;

	map = mlx->map_data->map;
	row = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] == 'P')
			{
				(*player_loc)[0] = row;
				(*player_loc)[1] = col;
				return ;
			}
			col++;
		}
		row++;
	}
}
