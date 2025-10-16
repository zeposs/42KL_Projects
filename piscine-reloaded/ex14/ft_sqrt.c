/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:22:14 by zernest           #+#    #+#             */
/*   Updated: 2025/10/17 00:36:02 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (nb < 0)
		return (0);
	while (i < nb)
	{
		if (i * i == nb)
			res = i;
		i++;
	}
	return (res);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%d\n",(ft_sqrt(15)));
// 	return(0);
// }
