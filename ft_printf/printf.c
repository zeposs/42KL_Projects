/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:35:58 by zernest           #+#    #+#             */
/*   Updated: 2024/06/25 23:32:01 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

static void	ft_write(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '%' || str[i] != '\0')
	{
		write(1, str[i], 1);
		i++;
	}

	if (str[i] == 's')
	
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_start (args, format);	
	int i;
	char x;

	ft_write(format);
}
