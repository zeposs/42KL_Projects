/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:22:54 by zernest           #+#    #+#             */
/*   Updated: 2024/09/23 18:45:14 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	exit_error_str(char *str, int n)
{
	int	len;

	len = ft_strlen(str);
	if (n == 1)
		ft_putstr_err("Error: command not found: ");
	else if (n == 2)
	{
		ft_putstr_err(str);
		write(2, "\n", 1);
		exit(1);
	}
	else
		ft_putstr_err("Error: file or directory doesn't exist: ");
	ft_putstr_err(str);
	write(2, "\n", 1);
	exit(1);
}

void	free_available_paths(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	exit_error(int n)
{
	if (n)
		write(2, "Error: Wrong pipex usage\n", 25);
	else
		perror("Error");
	exit(1);
}
