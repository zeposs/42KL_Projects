/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:27:30 by zernest           #+#    #+#             */
/*   Updated: 2024/06/15 19:26:29 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*result;

	if (!s)
		return (0);
	i = -1;
	result = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	len = ft_strlen(s);
	while (++i < len)
	{
		result[i] = (*f)(i, s[i]);
	}
	result[i] = '\0';
	return (result);
}

/* #include <stdio.h>
int	main(void)
{
	char	*str = "Hello, World!";
	char	*ret;
	ret = ft_strmapi(str,);
	printf("%s", ret);
} */