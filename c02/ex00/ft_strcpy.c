/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:09:54 by zernest           #+#    #+#             */
/*   Updated: 2024/05/01 15:09:55 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	letter;

	letter = 0;
	while (src[letter] != '\0')
	{
		dest[letter] = src[letter];
		letter++;
	}
	return (dest);
}

/* int	main(void)
{
	char	dup[500];

	ft_strcpy(dup, "source");
	printf("%s\n", dup);
} */
