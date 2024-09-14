/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:37:10 by zernest           #+#    #+#             */
/*   Updated: 2024/06/05 17:20:31 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*string;
	size_t			i;

	string = s;
	i = 0;
	while (i < n)
	{
		*string++ = '\0';
		i++;
	}
}

/* #include <stdio.h>

int	main(void)
{
	char    str[] = "hel ldd";
	ft_bzero(str, 5);
	int i = 0;
	int j = 0;
	while (j == 0 || j < i)
	{
		if (str[i] == '\0' && str[j] != '\0')
			break ;
		if (str[i] == '\0')
			write (1, "X", 1);
		else
			write (1, &str[i], 1);
		i++;
		j = i - 1;
	}
	return (0);
} */