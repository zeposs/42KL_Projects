/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:41:33 by zernest           #+#    #+#             */
/*   Updated: 2024/05/13 18:27:15 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);
void	ft_putchar(char c);
void	printNbr(int n, int symCount, char *sym);
int		check_char(char *sym);

/* int	main(void)
{
	int		no;
	char	*sym;

	no = 543;
	sym = "01";
	ft_putnbr_base(no, sym);
} */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	symCount;

	symCount = 0;
	while (base[symCount] != '\0')
	{
		if (base[symCount] == 45 || base[symCount] == 43)
			return ;
		symCount++;
	}
	if (symCount < 2)
		return ;
	if (check_char(base) == 1)
		return ;
	printNbr(nbr, symCount, base);
}

void	printNbr(int n, int symCount, char *sym)
{
	long	overflow;

	overflow = n;
	if (overflow < 0)
	{
		overflow = overflow * -1;
		ft_putchar('-');
	}
	if (overflow >= symCount)
		printNbr(overflow / symCount, symCount, sym);
	ft_putchar(sym[overflow % symCount]);
}

int	check_char(char *sym)
{
	int i;
    int j;

    j = 0;
	while (sym[j] != '\0')
	{
		i = j + 1;
		while (sym[i] != '\0')
		{
			if (sym[j] == sym[i])
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}