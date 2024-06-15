/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:14:10 by zernest           #+#    #+#             */
/*   Updated: 2024/06/15 19:29:33 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	new_len;
	char	*new_s;

	if (!s)
		return (0);
	i = -1;
	if (start >= ft_strlen(s) || len == 0)
	{
		return ((char *)malloc(1));
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
/* #include <stdio.h>
int	main(void)
{
	char *str = "Hello, World!";
	char *ret;

	ret = ft_substr(str, 7, 4);
	printf("%s", ret);
} */