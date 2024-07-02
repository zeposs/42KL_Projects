/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:33:22 by zernest           #+#    #+#             */
/*   Updated: 2024/07/02 21:43:34 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	no;
	long	temp;
	int		len;

	temp = n;
	no = n;
	len = 0;
	while (temp > 0)
	{
		temp /= 10;
		len++;
	}
	if (no < 0)
	{
		no = no * -1;
		ft_putchar('-');
	}
	if (no >= 10)
	{
		ft_putnbr(no / 10);
	}
	ft_putchar(no % 10 + '0');
	return (len);
}
