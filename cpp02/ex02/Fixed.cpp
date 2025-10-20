#include "Fixed.hpp"

Fixed::Fixed() : fpn(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fpn = other.getRawBits();
}
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this !=	&other)
	{
		this->fpn = other.getRawBits();
	}
	return (*this);
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	fpn = n << f_bits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	fpn = roundf(f * (1 << f_bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fpn);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fpn = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)fpn / (1 << f_bits));
}

int Fixed::toInt(void) const
{
	return (fpn >> f_bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}