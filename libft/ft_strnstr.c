/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:43:35 by zernest           #+#    #+#             */
/*   Updated: 2024/06/15 18:17:51 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return ((char *)big);
	i = -1;
	while (*big && ++i < len)
	{
		if (*big == *little)
		{
			j = 0;
			while (little[j] != '\0' && big[j] == little[j] && i + j < len)
			{
				j++;
			}
			if (little[j] == '\0')
			{
				return ((char *)big);
			}
		}
		big++;
	}
	return (NULL);
}

/* #include <stdio.h>

int	main(void)
{
	char *a;
	a = ft_strnstr("hello world", "ello", 1);
	printf("%s\n", a);
	return (0);
} */