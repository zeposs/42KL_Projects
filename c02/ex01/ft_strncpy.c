/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:32:40 by zernest           #+#    #+#             */
/*   Updated: 2024/05/02 13:32:47 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	letter;

	letter = 0;
	while ((letter < n) && (src[letter] != '\0'))
	{
		dest[letter] = src[letter];
		letter++;
	}
	dest[letter] = '\0';
	return (dest);
}

/* int	main(void)
{
	char	dup[500];
	int		new;

	ft_strncpy(dup, "Hello", 3);
	new = 0;
	while (dup[new] != '\0')
	{
		write(1, &dup[new], 1);
		new ++;
	}
} 
