/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:35:58 by zernest           #+#    #+#             */
/*   Updated: 2024/07/02 22:16:34 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	len = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			len += ft_putchar(format[i]);
		}
		if (format[i] == '%')
		{
			len += typelist(args, format[i + 1]);
			i++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

/* #include <stdio.h>
int	main(void)
{
	int	fake;
	int	real;

	fake = ft_printf(" %p %p ", 0, 0);
	write(1, "%%", 1);
	write(1, "\n", 1);
	real = printf(" %p %p ", 0, 0);
	write(1, "\n", 1);
	printf("fake value: %d", fake);
	write(1, "\n", 1);
	printf("real value: %d", real);
} */
