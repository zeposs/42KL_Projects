/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 20:24:44 by zernest           #+#    #+#             */
/*   Updated: 2024/06/10 17:42:30 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	main(void)
{
	const char str[] = "Hello World!";
	const char ch = 'o';
	char *ret;P

	ret = memchr(str, ch, 5);

	printf("%s", ret);

	return (0);
}