void    rush(int x,int y)
{
    char    a;
    char    b;
    char    c;
    int    d;
    int    e;
    char newline;
    int f;
    char    g;

    a = '/';
    b = '*';
    c = '\';
    d = 1;
    e = 1;
    newline = '\n';
    g = ' ';

    while(e <= y)
    {
        d = 1;
        while(d <= x)
        {
            if (d == 1 && e < 2 )
            {
                write (1, &a, 1);
            }
            else if (d == x && e < 2 )
            {
                write (1, &c, 1);
            }
            else if (d >= 2 && e >= 2 && d < 4 )
            {
                write (1, &g, 1);
            }
            else if (d == 1 && e == y)
            {
                write (1, &c, 1);
            }
            else if (d == x && e == y)
            {
                write (1, &a, 1);
            }
            else if (d < 5)
            {
                write (1, &b, 1);
            }
            d++;
        }
        write (1, &newline, 1);
        e++;
    }
}

int main(void)
{
    rush(4, 4);
    return 0;
}