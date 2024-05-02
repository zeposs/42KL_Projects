#include <unistd.h>

void	rush(int width, int height);
void	ft_putchar(char sym, int width);

int	main(void)
{
	rush(1, 5);
}
void	rush(int width, int height)
{
	char	backslash;
	char	slash;
	char	space;
	char	star;
	char	newliner;
	int		rows;
	int		cell;

	backslash = '\\';
	slash = '/';
	space = ' ';
	star = '*';
	newliner = '\n';
	rows = 1;
	cell = 1;
	while (rows <= height)
	{
		if (rows == 1)
		{
			ft_putchar(slash, 1);
			ft_putchar(star, width - 2);
			ft_putchar(backslash, 1);
		}
		else if (rows > 1 && rows < height)
		{
			ft_putchar(star, 1);
			ft_putchar(space, width - 2);
			ft_putchar(star, 1);
		}
		else
		{
			ft_putchar(backslash, 1);
			ft_putchar(star, width - 2);
			ft_putchar(slash, 1);
		}
		rows++;
		write(1, &newliner, 1);
	}
}
void	ft_putchar(char sym, int width)
{
	int	initial;

	initial = 0;
	while (initial < width)
	{
		write(1, &sym, 1);
		initial++;
	}
}
