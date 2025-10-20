#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cstdio>
#include <cmath>

class Fixed
{
	private:
		int	fpn;
		static const int f_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		Fixed(const float f);
		Fixed(const int n);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

#endif