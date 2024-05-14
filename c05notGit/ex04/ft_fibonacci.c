/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:48:45 by zernest           #+#    #+#             */
/*   Updated: 2024/05/14 18:10:07 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_fibonacci(int index)
{
	if (index == 0)
		return (0);
	if (index < 0)
		return (-1);
	if (index == 1 || index == 2)
		return (1);
	else
		return (ft_fibonacci(index - 1)) + (ft_fibonacci(index - 2));
}

/* #include <stdio.h>
int	main(void)
{
	int num = 0;
	int index = 10;

	while (num < index)
	{
		printf("%i ", ft_fibonacci(num));
		num++;
	}
} */