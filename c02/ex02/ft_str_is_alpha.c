/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:05:37 by zernest           #+#    #+#             */
/*   Updated: 2024/05/03 13:05:38 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	if (*str == '\0')
	{
		return (1);
	}
	else
	{
		while (*str != '\0')
		{
			if (!((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')))
			{
				return (0);
			}
			str++;
		}
		return (1);
	}
}

/* int	main(void)
{
	int	a;

	a = ft_str_is_alpha("hello") + '0';
	write(1, &a, 1);
} */
