/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:01:38 by zernest           #+#    #+#             */
/*   Updated: 2024/12/15 00:15:41 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int ac, char **av)
{
	t_stack	*a;

	a = ft_process(ac, av);
	if (!a || ft_checkdup(a))
	{
		ft_free(&a);
		ft_error();
	}
	if (!ft_checksorted(a))
		ft_sort(&a);
	ft_free(&a);
	return (0);
}

t_stack	*ft_process(int ac, char **av)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (ac < 2)
		ft_error();
	if (ac == 2)
		a = ft_sub_process(av);
	else
	{
		while (i < ac)
		{
			j = ft_atoi2(av[i]);
			ft_add_back(&a, ft_stack_new(j));
			i++;
		}
	}
	return (a);
}

t_stack	*ft_sub_process(char **av)
{
	t_stack	*a;
	char	**temp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	temp = ft_split(av[1], 32);
	while (temp[i])
	{
		j = ft_atoi2(temp[i]);
		ft_add_back(&a, ft_stack_new(j));
		i++;
	}
	ft_freestr(temp);
	free(temp);
	return (a);
}

int	ft_atoi2(const char *str)
{
	int				mod;
	long long int	i;

	i = 0;
	mod = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		mod = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
		ft_error();
	return (mod * i);
}

void	ft_error(void)
{	
	write (2, "Error\n", 6);
	exit(1);
}
