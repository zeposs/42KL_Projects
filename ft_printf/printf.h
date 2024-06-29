/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:24:36 by zernest           #+#    #+#             */
/*   Updated: 2024/06/29 20:22:00 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H 
# define PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...);
int	typelist(va_list args, char c);
int	ft_strlen(char const *str);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);

#endif