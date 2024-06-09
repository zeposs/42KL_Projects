/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 20:24:44 by zernest           #+#    #+#             */
/*   Updated: 2024/06/08 20:24:44 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	main(void)
{
	const char str[] = "Hello World!";
	const char ch = 'o';
	char *ret;

	ret = memchr(str, ch, 4);

	printf("%s", ret);

	return (0);
}