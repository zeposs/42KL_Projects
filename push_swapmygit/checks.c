/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:25:28 by zernest           #+#    #+#             */
/*   Updated: 2024/10/21 20:41:39 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	alpha_check(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (ft_isalpha(av[i][j]))
				exit_error_str("Error: Alphabetical character found");
			j++;
		}
		i++;
	}
}

int	check_error(char **av, int i, int j)
{
	while (av[i])
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (issign(av[i][j]))
			{
				j++;
				if (!ft_isdigit(av[i][j]))
					return (0);
			}
			else if (ft_isdigit(av[i][j]))
			{
				j++;
				if (av[i][j] == '\0')
					break ;
				if (!ft_isdigit(av[i][j]) && !isspace(av[i][j]))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_args(char **argv)
{
	alpha_check(argv);
	if (!check_error(argv, 1, 0))
		return (0);
	return (1);
}

int	ft_checkdup(t_stack *a)
{
	t_stack	*temp;

	while (a)
	{
		temp = a->next;
		while (temp)
		{
			if (a->nbr == temp->nbr)
				return (1);
			temp = temp->next;
		}
		a = a->next;
	}
	return (0);
}

int	ft_checksorted(t_stack *a)
{
	int	i;

	i = a->nbr;
	while (a)
	{
		if (i > a->nbr)
			return (0);
		i = a->nbr;
		a = a->next;
	}
	return (1);
}
