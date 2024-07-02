/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowerhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:50:00 by zernest           #+#    #+#             */
/*   Updated: 2024/07/02 21:32:46 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printinghex(uintptr_t ptr, char *base)
{
	if (ptr >= 16)
		ft_printinghex((ptr / 16), base);
	write(1, &base[ptr % 16], 1);
}

int	ft_lowerhex(unsigned int n)
{
	int				count;
	unsigned int	countn;

	count = 0;
	countn = n;
	if (!n)
	{
		ft_putchar('0');
		return (1);
	}
	else
	{
		while (countn > 0)
		{
			countn /= 16;
			count++;
		}
		ft_printinghex(n, "0123456789abcdef");
	}
	return (count);
}
