/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:07:02 by samartin          #+#    #+#             */
/*   Updated: 2024/11/01 17:46:26 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Constructors (Default, copy, from int, and from float) and destructor */

Fixed::Fixed(void)
{
	this->value = 0;
}

Fixed::Fixed(const Fixed& orig)
{
	this->value = orig.getRawBits();
}

Fixed::Fixed(const int& intnum)
{
	this->setRawBits(intnum << this->fraction);
}

Fixed::Fixed(const float& floatnum)
{
	this->setRawBits((int)roundf(floatnum * (1 << this->fraction)));
}

Fixed::~Fixed(void) {}


/* Assignment operator function */

Fixed& Fixed::operator=(const Fixed& rs)
{
	this->value = rs.getRawBits();
	return (*this);
}


/* Comparison operator functions */

bool Fixed::operator==(const Fixed& rs) const
{
	if (this->value == rs.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator!=(const Fixed& rs) const
{
	if (this->value != rs.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator<(const Fixed& rs) const
{
	if (this->value < rs.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator>(const Fixed& rs) const
{
	if (this->value > rs.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator<=(const Fixed& rs) const
{
	if (this->value <= rs.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator>=(const Fixed& rs) const
{
	if (this->value >= rs.getRawBits())
		return (true);
	else
		return (false);
}


/* Arithmetic operator functions */

Fixed Fixed::operator+(const Fixed& rs) const
{
	Fixed result;

	result.setRawBits(this->value + rs.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed& rs) const
{
	Fixed result;

	result.setRawBits(this->value - rs.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed& rs) const
{
	Fixed result;
	long long aux1;
	long long aux2;
	int displ = 0;

	while (displ < 8 && !(aux1 & 1) && !(aux2 & 1))
	{
		aux1 = aux1 >> 1;
		aux2 = aux2 >> 1;
		displ++;
	}
	aux = (long long)this->value * (long long)rs.getRawBits();
	aux = (aux >> (this->fraction)) & (long long)FX_INT_MAX;
	result.setRawBits(aux);
	return (result);
}

Fixed Fixed::operator/(const Fixed& rs) const
{
	Fixed result;
	long long aux;

	aux = (long long)this->value << this->fraction / rs.getRawBits();
	aux = (aux >> this->fraction) & (long long)FX_INT_MAX;
	result.setRawBits(aux);
	return (result);
}


/* Increment and decrement operators. The ones getting no parameter and
 * returning the instance are for prefix, the ones getting an int as parameter
 * and returning a copy are for sufix */

Fixed& Fixed::operator++(void)
{
	this->value = this->value + 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed aux(*this);

	this->value = this->value + 1;
	return (aux);
}

Fixed& Fixed::operator--(void)
{
	this->value = this->value - 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed aux(*this);

	this->value = this->value - 1;
	return (aux);
}


/* Getter and setter */

int Fixed::getRawBits(void) const
{
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}


/* Type conversion Functions */

float Fixed::toFloat(void) const
{
	return (this->value / (float)(1 << this->fraction));
}

int Fixed::toInt(void) const
{
	return(this->value >> this->fraction);
}


/* Static class functions. Return the bigger or smaller of the two parameters
 * passed */

Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1.getRawBits() <= f2.getRawBits())
		return(f1);
	else
		return(f2);
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1.getRawBits() <= f2.getRawBits())
		return(f1);
	else
		return(f2);
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1.getRawBits() >= f2.getRawBits())
		return(f1);
	else
		return(f2);
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1.getRawBits() >= f2.getRawBits())
		return(f1);
	else
		return(f2);
}

/* This is an overload function that works globally for the << operator to
 * allow it to output the float value of a Fixed object to an output stream. */
std::ostream& operator<<(std::ostream& stm, const Fixed& val)
{
	stm << val.toFloat();
	return (stm);
}
