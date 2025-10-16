/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 01:11:26 by zernest           #+#    #+#             */
/*   Updated: 2025/10/17 02:36:58 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c);

// void	ft_putchar(char c)
// {
// 	write (1, &c, 1);
// }

int	ft_strcmp(const char *s1, const char *s2)
{
	int	a;

	a = 0;
	while ((s1[a] != '\0') && (s2[a] != '\0') && (s1[a] == s2[a]))
		a++;
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}

void	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_sort_params(char **av, int ac)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (i < ac - 1)
	{
		j = 1;
		while (j < ac - 1)
		{
			if (ft_strcmp(av[j], av[j + 1]) > 0)
			{
				temp = av[j];
				av[j] = av[j + 1];
				av[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;

	if (ac > 1)
	{
		ft_sort_params(av, ac);
		i = 1;
		while (i < ac)
		{
			ft_putstr(av[i]);
			ft_putchar('\n');
			i++;
		}
	}
	return (0);
}
