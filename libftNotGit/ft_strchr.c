/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:01:03 by zernest           #+#    #+#             */
/*   Updated: 2024/06/08 19:33:49 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{	
			return ((char *)s);
		}
		else
			s++;
	}
	return (NULL);
}

/* #include <stdio.h>

int	main(void)
{
	const char str[] = "Hello World!";
	const char ch = 'o';
	char *ret;

	ret = ft_strchr(str, ch);

	printf("%s", ret);

	return (0);
} */
