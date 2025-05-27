/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 03:47:37 by albillie          #+#    #+#             */
/*   Updated: 2025/02/12 17:12:31 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors
Fixed::Fixed(const int intValue)
{
	// std::cout << "Int constructor called" << std::endl;
	this->FixedPoint = intValue << this->RawBits;
}

Fixed::Fixed(const float floatValue)
{
	// std::cout << "Float constructor called" << std::endl;
	this->FixedPoint = roundf(floatValue * (1 << this->RawBits));
}

Fixed::Fixed(const Fixed& fixed)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->FixedPoint = 0;
}

// Destructors
Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

// Cpy assignment operator
Fixed &Fixed::operator=(const Fixed &fixed)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->FixedPoint = fixed.FixedPoint;
	return (*this);
}

// Getters
int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->FixedPoint);
}

// Setters
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->FixedPoint = raw;
}

// Converters
float Fixed::toFloat(void) const
{
	return (float)(this->FixedPoint) / (1 << this->RawBits);
}

int	Fixed::toInt(void) const
{
	return (this->FixedPoint >> this->RawBits);
}

// Overload Operator
std::ostream &operator<<(std::ostream &out, Fixed const &fixed)
{
	out << fixed.toFloat();
	return (out);
}

// Comparison operators

bool Fixed::operator>(const Fixed &fixed)
{
	return (this->toFloat() > fixed.toFloat());
}

bool Fixed::operator<(const Fixed &fixed)
{
	return (this->toFloat() < fixed.toFloat());
}

bool Fixed::operator>=(const Fixed &fixed)
{
	return (this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator<=(const Fixed &fixed)
{
	return (this->toFloat() <= fixed.toFloat());
}

bool Fixed::operator==(const Fixed &fixed)
{
	return (this->toFloat() == fixed.toFloat());
}

bool Fixed::operator!=(const Fixed &fixed)
{
	return (this->toFloat() != fixed.toFloat());
}

// Arithmetic operators

Fixed Fixed::operator+(const Fixed &fixed)
{
	return (this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed)
{
	return (this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed)
{
	return (this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed)
{
	return (this->toFloat() / fixed.toFloat());
}

// Increment, decrement, etc.. operators

Fixed &Fixed::operator++()
{
	this->FixedPoint++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	operator++();
	return (*this);
}

Fixed &Fixed::operator--()
{
	this->FixedPoint--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	operator--();
	return (*this);
}

// Comparison function

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.toFloat() < b.toFloat())
	{
		return (a);
	}
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() < b.toFloat())
	{
		return (a);
	}
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.toFloat() > b.toFloat())
	{
		return (a);
	}
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() > b.toFloat())
	{
		return (a);
	}
	return (b);
}
