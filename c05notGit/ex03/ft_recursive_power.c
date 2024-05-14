/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:59:48 by zernest           #+#    #+#             */
/*   Updated: 2024/05/14 16:37:26 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_recursive_power(int nb, int power)
{

	if (power == 0 || (nb == 0 && power == 0))
		return (1);
    if (power < 0)
        return (0);
	else
	{
		return (nb * ft_recursive_power(nb, power - 1));
	}
}

/* #include <stdio.h>

int	main(void)
{
	int a = 2;
	int b = 5;

	int result = ft_recursive_power(a, b);
	printf("%d\n", result);
	return (0);
} */