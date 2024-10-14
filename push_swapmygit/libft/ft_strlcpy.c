/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:49:28 by zernest           #+#    #+#             */
/*   Updated: 2024/06/15 18:10:06 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
	{
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/* #include <stdio.h>

int	main(void)
{
	char destination[20]; // Destination buffer with size 20
	const char *source = "This is a long string";

	// Safe copy, even if the source string is longer than the destination
	size_t copied_length = ft_strlcpy(destination, source, sizeof(destination));

	printf("Copied string: %s\n", destination);
	printf("Length of source string: %zu\n", copied_length);

	return (0);
} */