/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:46:41 by zernest           #+#    #+#             */
/*   Updated: 2024/07/28 19:44:55 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	sum;
	size_t	i;
	char	*new_str;

	if ((s1 == NULL && s2 == NULL) || (!s1))
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	sum = len1 + len2 + 1;
	new_str = (char *)malloc(sum);
	if (new_str == NULL)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		new_str[i] = s1[i];
	while (s2[i - len1] != '\0')
	{
		new_str[i] = s2[i - len1];
		i++;
	}
	new_str[i] = '\0';
	free(s1);
	return (new_str);
}

int	ft_strchr(char *str, int c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	i;

	i = 0;
	res = (char *)malloc(ft_strlen(s1) + 1);
	if (res == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_substr(char const *s, int start, int len)
{
	int		i;
	int		new_len;
	char	*new_s;

	if (!s)
		return (0);
	i = -1;
	if (start >= ft_strlen(s) || len == 0)
	{
		return (ft_strdup(""));
	}
	new_len = 0;
	if (start >= ft_strlen(s) || len == 0)
		return (NULL);
	if (len > ft_strlen(s) - start)
		new_len = ft_strlen(s) - start;
	else
		new_len = len;
	new_s = (char *)malloc(new_len + 1);
	if (new_s == NULL)
		return (NULL);
	while (++i < new_len)
		new_s[i] = s[start + i];
	new_s[i] = '\0';
	return (new_s);
}
