/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:31:03 by zernest           #+#    #+#             */
/*   Updated: 2024/06/15 19:27:55 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	isset(char const *set, char c)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		else
			set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;
	size_t	start;
	size_t	trimlen;

	if (!s1)
		return (0);
	end = ft_strlen(s1) - 1;
	start = 0;
	while (isset(set, s1[start]))
	{
		start++;
	}
	while (isset(set, s1[end]))
	{
		end--;
	}
	trimlen = end - start + 1;
	return (ft_substr(s1, start, trimlen));
}

/* #include <stdio.h>

int	main(void)
{
	char	*ret;

	ret = ft_strtrim("abcdab", "a");
	printf("%s", ret);
} */