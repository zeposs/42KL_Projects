#include <unistd.h>

void ft_putchar(char c)
{
    write (1, &c, 1);
    write (1, "\n", 1);
}

void ft_putchar_first(char c)
{
    ft_putchar(c);
}