/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 20:24:44 by zernest           #+#    #+#             */
/*   Updated: 2024/06/13 17:29:16 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*char_s;
	size_t		i;

	char_s = (const char *)s;
	i = 0;
	while (i < n)
	{
		if (*char_s == c)
		{
			return ((void *)char_s);
		}
		else
		{
			char_s++;
			i++;
		}
	}
	return (NULL);
}

/* #include <stdio.h>

int	main(void)
{
	const char str[] = "Hello World!";
	const char ch = 'o';
	char *ret;

	ret = ft_memchr(str, ch, 5);

	printf("%s", ret);

	return (0);
} */