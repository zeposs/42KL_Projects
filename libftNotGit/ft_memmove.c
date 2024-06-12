/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:10:06 by zernest           #+#    #+#             */
/*   Updated: 2024/06/10 17:52:42 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	const unsigned char	*source;

	dest = dst;
	source = src;
	if (dest < source)
	{
		while (len != 0)
		{
			*dest++ = *source++;
			len--;
		}
	}
	else
	{
		while (len != 0)
		{
			dest[len] = source[len];
			len--;
		}
	}
	return (dest);
}

/* #include <stdio.h>

int	main(void)
{
	char src[] = "12345";
	char dst[30];
	ft_memmove(src + 2, src, 2);
	printf("%s", dst);
} */