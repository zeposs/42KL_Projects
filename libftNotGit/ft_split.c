/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:58:51 by zernest           #+#    #+#             */
/*   Updated: 2024/06/12 21:35:57 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // for optional testing (remove in final code)
#include <stdlib.h>
#include <string.h> // for strndup

char	*ft_strcpy(char *dest, const char *src)
{
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	char	**split_words;
	int		i;

	i = 0;
	if (s == NULL)
	{
		return (NULL);
	}
	word_count = ft_count_words(s, c);
	split_words = malloc(sizeof(char *) * (word_count + 1));
	if (split_words == NULL)
	{
		return (NULL);
	}
	i = 0, start = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!start)
				start = 1;
		}
		else if (start)
		{
			split_words[i++] = ft_strcpy(malloc(start + 1), s - start);
			if (!split_words[i - 1])
				return (NULL);
			start = 0;
		}
		s++;
	}
	if (start)
	{
		split_words[i++] = ft_strcpy(malloc(strlen(s) - start + 1), s - start);
		if (!split_words[i - 1])
			return (NULL);
	}
	split_words[i] = NULL;
	return (split_words);
}
