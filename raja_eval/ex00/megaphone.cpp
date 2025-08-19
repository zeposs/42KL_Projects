#include <cctype>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
 		for (int i = 1; i < argc; ++i)
		{
			for (int j = 0; argv[i][j]; ++j)
				std::cout << (char)std::toupper(argv[i][j]);
			if (i < argc - 1)
				std::cout << " ";
		}
	std::cout << std::endl;
	}
	return (0);
}

// the std::cout is like the printf or C, and the std::endl is more of like
// a \n but then it also flushes the buffer to prvent any moemory leaks, 
// which is slightly slower, but like safer for logs and outputs.