/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 20:04:44 by zernest           #+#    #+#             */
/*   Updated: 2024/05/10 20:12:59 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	while (*str)
	{
		int i;
		int temp;

		if (to_find = '\0')
			return (str);
		if (*str == *to_find)
		{
			i = 0;
			temp = 0;
			while (to_find[i] != '\0')
			{
				if (str[i] != to_find[i])
					temp = 1;
				i++;
			}
			if (temp = 0)
				return (str);
		}
	}
	str++;
}

int main(void)
{
    char a = 0;
    a = ft_strstr("hey hi halo", "hi");
    printf ("%d\n", a);
}