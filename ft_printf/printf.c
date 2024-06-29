/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:35:58 by zernest           #+#    #+#             */
/*   Updated: 2024/06/29 20:19:03 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start (args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			typelist(args, format[++i]);
			i++;
		}
		else
		{	
		ft_putchar(format[i]);
		i++;
		}
	}
	return (1);
}

int	main(void)
{
	ft_printf("hello %d", 1232);
}