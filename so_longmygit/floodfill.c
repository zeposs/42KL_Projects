/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 00:41:12 by zernest           #+#    #+#             */
/*   Updated: 2024/12/09 00:53:29 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    **dup_map(t_mlx *mlx)
{
    char **map_dup;
    char **map_sample;
    int    row;

	map_dup = malloc(sizeof(char *) * (mlx->win_y + 1));
	if (map_dup == NULL)
		exit_err_string(&mlx, "Failed to clone map for flood fill\n");
    map_sample = mlx->map_data->map;
    row = -1;
    while (map_sample[++row])
        map_dup[row] = ft_strdup(map_sample[row]);
    map_dup[row] = NULL;
    return (map_dup);
}