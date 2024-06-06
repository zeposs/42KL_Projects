#include <unistd.h>

int ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
        c = c - 32;
    return (c);
}

/* int main(void)
{
    char c;
    c = ft_toupper('b');
    write(1, &c, 1);
} */