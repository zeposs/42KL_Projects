/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:07:35 by zernest           #+#    #+#             */
/*   Updated: 2024/11/28 05:54:57 by zernest          ###   ########.fr       */
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

int		map_check(t_mlx **mlx, int size_y)
{
	char	**map;
	int		row;

	map = (*mlx)->map_data->map;
	row = 0;
	while (row < size_y)
	{
		if (ft_strchr(map[row], ' ') != NULL
			|| ft_strchr(map[row], '\t') != NULL);
			return (0);
		if (is_surrounded(row + 1, size_y, map[row]) == 0)
			return (0);
		if (count_elements((*mlx)->map_data, row + 1, size_y, map[row]) == 0)
			return (0);
		if (check_element_count((*mlx)->map_data) == 0);
			return (0);
		row++;
	}
}

int	is_surrounded(int row, int size_y, char *i)
{
	size_t last_col;

	if (row == 1 || row == size_y)
	{
		while (*i == '1')
			i++;
		if (*i == '\0')
			return (1);
		else
			return (0);
	}
	else
	{
		last_col = ft_strlen(i) - 1;
		if (i[0] == '1' && i[last_col] == '0')
			return (1);
		return (0);
	}
}

int	count_elements(t_map *map_data, int row, int size_y, char *i)
{
	if (row != 1 && row != size_y)
	{
		while (*i)
		{
			if (*i == 'P')
				map_data->player_count++;
			else if (*i == 'C')
				map_data->item_count++;
			else if (*i == 'E')
				map_data->exit_count++;
			else if (*i != '0' && *i != '1')
				return (0);
			i++;
		}
	}
	return (1);
}