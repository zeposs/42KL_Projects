/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typelist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:55:15 by zernest           #+#    #+#             */
/*   Updated: 2024/06/29 20:20:14 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	typelist(va_list args, char c)
{
	if (c == 's')
		ft_putstr(va_arg(args, char *));
	else if (c == 'c')
		ft_putchar(va_arg(args, int));
	else if (c == '%')
		ft_putchar('%');
	else if (c == 'i' || c == 'd')
		ft_putnbr(va_arg(args, int));
	else if (c == 'p')
		ft_ptr(va_arg(args, void *));
	else if (c == 'x')
		ft_lowerhex(va_arg(args, unsigned int));
	else if (c == 'X')
		ft_upperhex(va_arg(args, unsigned int));
	return (0);
}
