/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:53:47 by zernest           #+#    #+#             */
/*   Updated: 2024/06/11 20:30:23 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	sum;
	size_t	i;
	char	*new_str;

	if (s1 == NULL && s2 == NULL)
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
	return (new_str);
}
/* 
#include <stdio.h>
int	main(void)
{
	char *str = "Hello, ";
	char *s2 = "World!";
	char *ret;

	ret = ft_strjoin(str, s2);
	printf("%s", ret);
} */