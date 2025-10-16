/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:06:56 by zernest           #+#    #+#             */
/*   Updated: 2025/10/16 23:12:52 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int n)
{
	if (n < 0)
		return (0);
	if (n == 0 || n == 1)
		return (1);
	return (n * ft_recursive_factorial(n - 1));
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%d\n", (ft_recursive_factorial(13)));
// 	return (0);
// }
