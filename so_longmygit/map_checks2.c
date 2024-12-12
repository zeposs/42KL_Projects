/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:07:35 by zernest           #+#    #+#             */
/*   Updated: 2024/12/12 19:13:54 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_element_count(t_map *map_data)
{
	if (map_data->player_count != 1)
		return (0);
	if (map_data->exit_count != 1)
		return (0);
	if (map_data->item_count < 1)
		return (0);
	return (1);
}
