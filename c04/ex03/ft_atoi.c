/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:40:29 by zernest           #+#    #+#             */
/*   Updated: 2024/05/12 18:13:06 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	num;
	int	i;
	int	countneg;

	countneg = 0;
	i = 0;
	num = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			countneg++;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	if (countneg % 2 == 0)
		return (num);
	return (num * -1);
}

/* #include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_atoi("-----2312"));
	printf("%d\n", ft_atoi("   \n --+-++-+-28354352"));
	printf("%d\n", ft_atoi("--2312"));
	printf("%d\n", ft_atoi("--2312"));
	printf("%d\n", ft_atoi("--2312"));
	printf("%d\n", ft_atoi("--2312"));
	printf("%d\n", ft_atoi("--2312"));
} */