/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:41:26 by zernest           #+#    #+#             */
/*   Updated: 2025/01/23 19:09:27 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
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
	write(2, "\n", 1);
	exit(1);
}

