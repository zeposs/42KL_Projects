/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:07:35 by zernest           #+#    #+#             */
/*   Updated: 2026/04/22 09:57:56 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_element_count(t_map *map_data)
{
	if (map_data->player_count != 1)
	{
		ft_putstr_err("Please ensure that the there is exactly 1 player spawn.\n");
		return (0);
	}
	if (map_data->exit_count != 1)
	{
		ft_putstr_err("Please ensure that the there is exactly 1 exit.\n");
		return (0);
	}
	if (map_data->item_count < 1)
	{
		ft_putstr_err("Please ensure that the there is at least 1 collectible.\n");
		return (0);
	}
	return (1);
}
