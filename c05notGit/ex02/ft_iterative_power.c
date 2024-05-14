/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:57:34 by zernest           #+#    #+#             */
/*   Updated: 2024/05/14 15:45:03 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	original;

	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	original = nb;
	i = 1;
	while (i < power)
	{
		nb = original * nb;
		i++;
	}
	return (nb);
}

/* #include <stdio.h>

int	main(void)
{
	int a;
	int b;
	a = 2;
	b = 5;
	int result = ft_iterative_power(a, b);
	printf("%d", result);
	return (0);
} */