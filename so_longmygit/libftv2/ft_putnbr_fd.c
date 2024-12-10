/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:33:22 by zernest           #+#    #+#             */
/*   Updated: 2024/06/13 15:43:20 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	no;

	no = n;
	if (no < 0)
	{
		no = no * -1;
		ft_putchar('-', fd);
	}
	if (no >= 10)
	{
		ft_putnbr_fd(no / 10, fd);
	}
	ft_putchar(no % 10 + '0', fd);
}

/* int	main(void)
{
	ft_putnbr_fd(23563231, 1);
} */
