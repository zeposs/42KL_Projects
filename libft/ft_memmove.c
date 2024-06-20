/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:10:06 by zernest           #+#    #+#             */
/*   Updated: 2024/06/18 19:16:48 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	const unsigned char	*source;
	size_t				i;

	if (!src && !dst)
		return (NULL);
	dest = dst;
	source = src;
	i = -1;
	if (dest < source)
	{
		while (++i < len)
			dest[i] = source[i];
	}
	else
	{
		while (len != 0)
		{
			len--;
			dest[len] = source[len];
		}
	}
	return (dest);
}

/* #include <stdio.h>

int	main(void)
{
	char src[] = "12345";
	char dst[30];
	char s[] = {65, 66, 67, 68, 69, 0, 45};
	char s0[] = { 0,  0,  0,  0,  0,  0, 0};
	ft_memmove(src + 2, src, 2);
	ft_memmove(s0, s, 7);
	printf("%s", dst);
} */