/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:48:44 by zernest           #+#    #+#             */
/*   Updated: 2024/04/28 18:48:45 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	d;
	int	e;

	d = 1;
	e = 1;
	while (e <= y)
	{
		d = 1;
		while (d <= x)
		{
			if (d == 1 && e == 1 || d == x && e == 1 || d == 1 && e == y
				d == x && e == y)
				ft_putchar('o');
			else if (d == 1 && e > 1 || d == x && e > 1)
				ft_putchar('|');
			else if (d > 1 && e > 1 && d < x && e < y)
				ft_putchar(' ');
			else
				ft_putchar('-');
			d++;
		}
		ft_putchar('\n');
		e++;
	}
}
