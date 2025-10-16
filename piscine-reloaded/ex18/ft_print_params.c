/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 01:00:08 by zernest           #+#    #+#             */
/*   Updated: 2025/10/17 01:08:31 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

// void	ft_putchar(char c)
// {
// 	write (1, &c, 1);
// }

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (ac == 1)
		return (0);
	while (av[i])
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			ft_putchar(av[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return (0);
}
