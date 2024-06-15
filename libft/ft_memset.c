/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:59:48 by zernest           #+#    #+#             */
/*   Updated: 2024/06/04 12:36:40 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*string;
	size_t			i;

	string = b;
	i = 0;
	while (i < len)
	{
		*string++ = c;
		i++;
	}
	return (b);
}

/* #include <stdio.h>
int	main(void)
{
	char test[100] = "Hello world!";
	printf("%s", ft_memset(test, 'X', 4));
} */