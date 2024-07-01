#include "printf.h"

static void	ft_printinghex(uintptr_t ptr, char *base)
{
	if (ptr >= 16)
		ft_printinghex((ptr / 16), base);
	write(1, &base[ptr % 16], 1);
}

int	ft_upperhex(unsigned int n)
{
	int				count;
	unsigned int	countn;

	count = 0;
	countn = n;
	if	(!n)
	{
		ft_putchar('0');
		return (1);
	}
	else
	{
		while (countn > 0)
		{
			countn /= 16;
			count++;
		}
		ft_printinghex(n, "0123456789ABCDEF");
	}
	return (count);
}