/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:58:51 by zernest           #+#    #+#             */
/*   Updated: 2024/06/15 20:03:48 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	save_space(size_t *i, int *j, int *word_len)
{
	*i = 0;
	*j = -1;
	*word_len = -1;
}

static int	word_count(const char *s, char c)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && i == 0)
		{
			i = 1;
			num++;
		}
		else if (*s == c)
		{
			i = 0;
		}
		s++;
	}
	return (num);
}

static char	*wordindex(const char *s, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	*ft_free(char **s, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		free(s[i]);
	free(s);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	i;
	int		j;
	int		word_len;

	if (!s)
		return (0);
	save_space(&i, &j, &word_len);
	res = ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!res)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && word_len < 0)
			word_len = i;
		else if ((s[i] == c || i == ft_strlen(s)) && word_len >= 0)
		{
			res[++j] = wordindex(s, word_len, i);
			if (!res[j])
				return (ft_free(res, j));
			word_len = -1;
		}
		i++;
	}
	return (res);
}

/* #include <stdio.h>

int	main(void)
{
	char **words;
	int i;

	words = ft_split("hello world, this is a test", ' ');
	if (!words)
		return (1);
	i = 0;
	while (words[i])
	{
		printf("Word %d: %s\n", i, words[i]);
		i++;
	}
	ft_free(words, i);
	return (0);
} */