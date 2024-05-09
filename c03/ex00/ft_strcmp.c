/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:49:42 by zernest           #+#    #+#             */
/*   Updated: 2024/05/09 13:27:24 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* #include <stdio.h> */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

/* int main(void)
{
	char s1[] = "a";
	char s2[] = "A";

	int ft_strcmpp = ft_strcmp(s1,s2);

	printf("ft_strcmp() function: %d\n", ft_strcmpp);
	return (0);
} */