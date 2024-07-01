#include "printf.h"

static void	ft_printinghex(uintptr_t ptr, char *base)
{
	if (ptr >= 16)
		ft_printinghex((ptr / 16), base);
	write(1, &base[ptr % 16], 1);
}

int	ft_ptr(void *ptr)
{
	int			count;
	uintptr_t	uptr;

	uptr = (uintptr_t)ptr;
	write(1, "0x", 2);
	count = 2;
	if (!ptr)
	{
		ft_putchar('0');
		return (3)
	}
	else
	{
		while (uptr > 0)
		{
			uptr /= 16;
			count++;
		}
		ft_printinghex((uintptr_t)ptr, "0123456789abcdef");
	}
	return (count);
}
