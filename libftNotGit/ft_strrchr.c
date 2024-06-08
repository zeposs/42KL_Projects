/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:20:32 by zernest           #+#    #+#             */
/*   Updated: 2024/06/08 19:25:37 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s != '\0')
	{
		if (*s == c)
		{
			last = (char *)s;
			s++;
		}
		else
			s++;
	}
	return (last);
}

/* #include <stdio.h>

int	main(void)
{
	const char s[] = "Hello World!";
	const char ch = 'o';
	char *ret;

	ret = ft_strrchr(s, ch);

	printf("%s", ret);

	return (0);
} */