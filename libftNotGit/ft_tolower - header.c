#include <unistd.h>

int ft_tolower(int c)
{
    if (c >= 'A' && c <= 'Z')
        c = c + 32;
    return (c);
}

int main(void)
{
    char c;
    c = ft_tolower('B');
    write(1, &c, 1);
}