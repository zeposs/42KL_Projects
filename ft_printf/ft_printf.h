/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:24:36 by zernest           #+#    #+#             */
/*   Updated: 2024/07/02 21:30:24 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	typelist(va_list args, char c);
int	ft_strlen(char const *str);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_ptr(void *ptr);
int	ft_lowerhex(unsigned int n);
int	ft_upperhex(unsigned int n);
int	ft_uint(unsigned int n);

#endif