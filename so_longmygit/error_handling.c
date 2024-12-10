/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:38:21 by zernest           #+#    #+#             */
/*   Updated: 2024/12/10 10:14:38 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_perr_string(t_mlx **mlx, char *msg)
{
	perror(msg);
	// function to free everything here
	exit(1);
}

void	ft_putstr_err(char *s)
{
	size_t	len;

	if (!s)
		return ;
	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	write(2, s, len);
}

void	exit_err_str(char *str)
{
	ft_putstr_err(str);
	write(2, "\n", 1);
	// function to free everything here too
	exit(1);
}

void	free_data(char ***map, int **player_loc)
{
	int	row;

	while ((*map)[row])
	{
		free((*map)[row]);
		row++;
	}
	free(*map);
	free(*player_loc);
}

void	ft_putstr_err_exit(char *s)
{
	size_t	len;

	if (!s)
		return ;
	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	write(2, s, len);
	exit(1);
}