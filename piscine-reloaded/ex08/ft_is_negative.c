/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:32:34 by zernest           #+#    #+#             */
/*   Updated: 2025/10/15 16:38:04 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_is_negative(int n)
{
	if (n == '+')
		ft_putchar('P');
	else if (n == '-')
		ft_putchar('N');
}

int	main(void)
{
	ft_is_negative('-');
	ft_putchar('\n');
	return (0);
}
