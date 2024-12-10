/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:18:12 by zernest           #+#    #+#             */
/*   Updated: 2024/06/15 20:00:53 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t				i;
	unsigned const char	*charstr1;
	unsigned const char	*charstr2;

	charstr1 = str1;
	charstr2 = str2;
	i = 0;
	while (i < n)
	{
		if (charstr1[i] != charstr2[i])
		{
			return (charstr1[i] - charstr2[i]);
		}
		i++;
	}
	if (i == n)
		return (0);
	else
		return (charstr1[i] - charstr2[i]);
}

/* #include <stdio.h>
int main(void)
{
	char s1[] = "abcd";
	char s2[] = "abce";

	int ft_strcmpp = ft_memcmp(s1,s2,5);

	printf("ft_memcmp() function: %d\n", ft_strcmpp);
	return (0);
} */