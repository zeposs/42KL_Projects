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

		bool operator>(const Fixed&) const;
		bool operator<(const Fixed&) const;
		bool operator>=(const Fixed&) const;
		bool operator<=(const Fixed&) const;
		bool operator==(const Fixed&) const;
		bool operator!=(const Fixed&) const;

		Fixed operator+(const Fixed&) const;
		Fixed operator-(const Fixed&) const;
		Fixed operator*(const Fixed&) const;
		Fixed operator/(const Fixed&) const;

		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

#endif