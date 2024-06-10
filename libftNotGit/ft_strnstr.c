/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:43:35 by zernest           #+#    #+#             */
/*   Updated: 2024/06/10 18:10:57 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	int		temp;
	size_t	j;

	j = 0;
	if (*little == '\0')
		return ((char *)big);
	while (*big && j < len)
	{
		if (*big == *little)
		{
			i = -1;
			temp = 0;
			while (little[++i] != '\0')
			{
				if (big[i] != little[i])
					temp = 1;
			}
			if (temp == 0)
				return ((char *)big);
		}
		big++;
		j++;
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