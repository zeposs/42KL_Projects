/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:38:58 by zernest           #+#    #+#             */
/*   Updated: 2024/12/12 17:27:14 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_data(char ***map, int **player_loc)
{
	int	row;

	row = 0;
	while ((*map)[row])
	{
		free((*map)[row]);
		row++;
	}
	free(*map);
	free(*player_loc);
}

void	free_mlx(t_mlx **mlx)
{
	int	i;

	i = -1;

	if ((*mlx)->map_data)
	{
		if ((*mlx)->map_data->map)
		{
			while ((*mlx)->map_data->map[++i])
				free((*mlx)->map_data->map[i]);
		}
		free((*mlx)->map_data);
	}
	if ((*mlx)->sprites != NULL)
	{
		if ((*mlx)->sprites->player)
			free((*mlx)->sprites->player);
	}
	free(*mlx);
}
