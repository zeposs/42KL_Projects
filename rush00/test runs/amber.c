#include <unistd.h>

{
	char slash = '/';
	char star = '*';
	char space = ' ';

	int a = 1;
	int b = 1;

	while (a <= x)
	{
		if (a == 1 || a == x)
		{
			write(1, $slash, 1);
		}
		else
		{
			write(1, $star, 1);
			a++;
		}
		while (b <= y)
		{
			if (b == 1 || b == y)
			{
				write(1, $star, 1);
			}
			else
			{
				write(1, $space, 1);
				b++;
			}

			int main()
			{
				int x, y;
				rush(x, y);
				return (0);
			}
