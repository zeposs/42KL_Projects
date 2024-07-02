/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typelist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:55:15 by zernest           #+#    #+#             */
/*   Updated: 2024/07/02 21:37:41 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	typelist(va_list args, char c)
{
	int	len;

	len = 0;
	if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == '%')
		len += ft_putchar('%');
	else if (c == 'i' || c == 'd')
		len += ft_putnbr(va_arg(args, int));
	else if (c == 'p')
		len += ft_ptr(va_arg(args, void *));
	else if (c == 'x')
		len += ft_lowerhex(va_arg(args, unsigned int));
	else if (c == 'X')
		len += ft_upperhex(va_arg(args, unsigned int));
	else if (c == 'u')
		len += ft_uint(va_arg(args, unsigned int));
	return (len);
}
