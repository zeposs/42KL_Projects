/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edliew <edliew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:09:24 by edliew            #+#    #+#             */
/*   Updated: 2024/04/28 15:30:01 by edliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	d;
	int	e;

	e = 1;
	while (e <= y)
	{
		d = 1;
		while (d <= x)
		{
			if (d == 1 && e == 1 || d == x && e == y && e > 1 && d > 1)
				ft_putchar('/');
			else if (d == x && e == 1 || d == 1 && e == y)
				ft_putchar('\\');
			else if (d > 1 && e > 1 && d < x && e < y)
				ft_putchar(' ');
			else
				ft_putchar('*');
			d++;
		}
		ft_putchar('\n');
		e++;
	}
}
