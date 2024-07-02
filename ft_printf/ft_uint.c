/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:50:52 by zernest           #+#    #+#             */
/*   Updated: 2024/07/02 21:33:14 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uint(unsigned int n)
{
	unsigned int	count;
	unsigned int	temp;

	count = 0;
	temp = n;
	while (temp > 0)
	{
		temp /= 10;
		count++;
	}
	if (n > 9)
	{
		ft_uint(n / 10);
		ft_uint(n % 10);
	}
	if (n < 10)
		ft_putchar(n + '0');
	if (!n)
		return (1);
	return (count);
}
