/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:32:42 by zernest           #+#    #+#             */
/*   Updated: 2024/05/14 15:49:35 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_recursive_factorial(int nb)
{
    if (nb == 0)
    {
        return (1);
    }

    if (nb < 0)
    {
        return (0);
    }

	if (nb == 1)
	{
		return (1);
	}
	else
	{
		return (nb * ft_recursive_factorial(nb - 1));
	}
}

/* #include <stdio.h>

int	main(void)
{
	int a;
	a = 15;
	int result = ft_recursive_factorial(a);
	printf("%d", result);
	return (0);
} */