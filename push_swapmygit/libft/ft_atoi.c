/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:20:22 by zernest           #+#    #+#             */
/*   Updated: 2024/10/14 17:55:35 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <limits.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	while (isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		num = num * 10 + (*str - '0');
		if (num * sign > INT_MAX)
			return (INT_MAX);
		if (num * sign < INT_MIN)
			return (INT_MIN);
		str++;
	}
	return (num * sign);
}

/* int	ft_atoi(const char *str)
{
	int	num;
	int	i;
	int	countneg;

	countneg = 0;
	i = 0;
	num = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == 43 || str[i] == 45)
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
	if (countneg > 1)
		return (0);
	else if (countneg == 1)
		return (num * -1);
	return (num);
} */

/* #include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_atoi("-a23a12"));
	printf("%d\n", ft_atoi("   \n -28354352"));
	printf("%d\n", ft_atoi("+2312"));
	printf("%d\n", ft_atoi(" -2312"));
	printf("%d\n", ft_atoi("--2312"));
	printf("%d\n", ft_atoi("--2312"));
	printf("%d\n", ft_atoi("--2312"));
} */