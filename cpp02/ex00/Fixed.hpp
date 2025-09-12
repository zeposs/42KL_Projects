#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cstdio>

class Fixed
{
	private:
		int	fpn;
		static const int f_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif