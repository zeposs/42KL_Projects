/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:43:35 by zernest           #+#    #+#             */
/*   Updated: 2024/04/28 12:43:39 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char symbol, int horizontal)
{
	int	start;

	start = 0;
	while (start < horizontal)
	{
		write(1, &symbol, 1);
		start++;
	}
}

void	aboveonecolumn_if(int horizontal)
{
	ft_putchar('/', 1);
	ft_putchar('*', horizontal - 2);
	ft_putchar('\\', 1);
}

void	aboveonecolumn_else_if(int horizontal)
{
	ft_putchar('*', 1);
	ft_putchar(' ', horizontal - 2);
	ft_putchar('*', 1);
}

void	aboveonecolumn_else(int horizontal)
{
	ft_putchar('\\', 1);
	ft_putchar('*', horizontal - 2);
	ft_putchar('/', 1);
}

void	onecolumn_if(int horizontal)
{
	ft_putchar('/', 1);
	ft_putchar('*', horizontal - 2);
}

void	onecolumn_else_if(int horizontal)
{
	ft_putchar('*', 1);
	ft_putchar(' ', horizontal - 2);
}

void	onecolumn_else(int horizontal)
{
	ft_putchar('\\', 1);
	ft_putchar('*', horizontal - 2);
}

void	rush(int horizontal, int vertical)
{
	int		line;
	char	newline;

	line = 1;
	newline = '\n';
	if (line == 1)
	{
		while (line <= vertical)
		{
			if (line == 1)
			{
				onecolumn_if(horizontal);
			}
			else if (line > 1 && line < vertical)
			{
				onecolumn_else_if(horizontal);
			}
			else
			{
				onecolumn_else(horizontal);
			}
			line++;
			write(1, &newline, 1);
		}
	}
	else
	{
		while (line <= vertical)
		{
			if (line == 1)
			{
				aboveonecolumn_if(horizontal);
			}
			else if (line > 1 && line < vertical)
			{
				aboveonecolumn_else_if(horizontal);
			}
			else
			{
				aboveonecolumn_else(horizontal);
			}
			line++;
			write(1, &newline, 1);
		}
	}
}

int	main(void)
{
	rush(1, 1);
}