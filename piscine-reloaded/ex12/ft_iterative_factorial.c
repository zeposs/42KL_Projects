/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:32:36 by zernest           #+#    #+#             */
/*   Updated: 2025/10/16 23:12:31 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb < 0 || nb > 12)
		return (0);
	while (nb > 0)
		result *= nb--;
	return (result);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%d\n", (ft_iterative_factorial(13)));
// 	return (0);
// }
