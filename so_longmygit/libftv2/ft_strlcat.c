/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:27:03 by zernest           #+#    #+#             */
/*   Updated: 2024/06/13 22:16:06 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	if (dstsize == 0)
		return (ft_strlen(src));
	dst_len = 0;
	while (dst[dst_len] != '\0' && dst_len < dstsize)
		dst_len++;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	while (src_len > 0 && dst_len < dstsize - 1)
	{
		dst[dst_len++] = *src++;
		src_len--;
	}
	dst[dst_len] = '\0';
	return (dst_len + src_len);
}

/* size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (dst[len] != '\0' && len < dstsize - 1)
		len++;
	if (len < dstsize - 1)
	{
		while (src[i] != '\0' && ((i + len) < (dstsize - 1)))
		{
			dst[len + i] = src[i];
			i++;
		}
		dst[len + i] = '\0';
	}
	return (len + i);
} */

/* #include <stdio.h>

int	main(void)
{
	char destination[8] = "Hello, ";
	const char *source = "world!";

	size_t new_length = ft_strlcat(destination, source, sizeof(destination));

	printf("Concatenated string: %s\n", destination);
	printf("New length (might be truncated): %zu\n", new_length);

	return (0);
} */