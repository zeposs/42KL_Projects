/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:44:02 by zernest           #+#    #+#             */
/*   Updated: 2024/05/14 13:20:16 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	result;

	i = 1;
	result = 1;
	if (nb <= 0)
	{
		if (nb == 0)
			return (1);
		else
			return (0);
	}
	while (i <= nb)
	{
		result = result * i;
		i++;
	}
	return (result);
}

/* int main(void)
{
	int a;
	a = ft_iterative_factorial(4);
	write(1, &a, 1);
} */