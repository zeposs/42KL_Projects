/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:27:03 by zernest           #+#    #+#             */
/*   Updated: 2024/06/08 18:54:17 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
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
}

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