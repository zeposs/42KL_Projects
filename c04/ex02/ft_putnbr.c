/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:30:03 by zernest           #+#    #+#             */
/*   Updated: 2024/05/12 15:26:05 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	no;

	no = nb;
	if ( no < 0)
	{
		no = no * -1;
		ft_putchar('-');
	}
	if (no >= 10)
	{
		ft_putnbr(no / 10);
	}	
	ft_putchar(no % 10 + '0');
}

/* int	main(void)
{
	ft_putnbr(23563231);
} */