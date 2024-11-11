/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:23:31 by zernest           #+#    #+#             */
/*   Updated: 2024/11/11 21:23:23 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define MAX_MAP_HEIGHT 100
#define MAX_MAP_WIDTH 100

void	ber_to_array(char *map)
{
	char	map[MAX_MAP_HEIGHT][MAX_MAP_WIDTH];
	char	*line;
	int		i;

	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		
	}
}