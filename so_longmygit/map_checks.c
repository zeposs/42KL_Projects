/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:07:35 by zernest           #+#    #+#             */
/*   Updated: 2024/11/16 02:10:47 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	calc_col(char **map, int size_y)
{
	int		row;
	size_t	fix_len;

	row = 0;
	fix_len = ft_strlen(map[0]);
	while (++row < size_y)
	{
		if (ft_strlen(map[row]) != fix_len)
			return (-1);
	}
	return (fix_len);
}

int	calc_row(char *map)
{
	int		fd;
	int		line_count;
	char	*line;

	fd = open (map, O_RDONLY);
	if (fd < 0)
	{
		perror("Error calculating rows");
		return (-1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		free(line);
		line_count++;
	}
	close(fd);
	return (line_count);
}
