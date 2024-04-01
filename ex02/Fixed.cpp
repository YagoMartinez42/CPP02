/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:07:02 by samartin          #+#    #+#             */
/*   Updated: 2024/03/29 18:03:35 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Constructors (Default, copy, from int, and from float) and destructor */

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed& orig)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = orig.getRawBits();
}

Fixed::Fixed(const int& intnum)
{
	std::cout << "Create from int constructor called" << std::endl;
	this->setRawBits(intnum << this->fraction);
}

Fixed::Fixed(const float& floatnum)
{
	std::cout << "Create from float constructor called" << std::endl;
	this->setRawBits((int)roundf(floatnum * (1 << this->fraction)));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}


/* Assignment operator function */

Fixed& Fixed::operator=(const Fixed& rs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = rs.getRawBits();
	return (*this);
}


/* Comparison operator functions */

bool Fixed::operator==(const Fixed& rs) const
{
	std::cout << "Equality comparison operator called" << std::endl;
	if (this->value == rs.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator!=(const Fixed& rs) const
{
	std::cout << "'Different to' comparison operator called" << std::endl;
	if (this->value != rs.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator<(const Fixed& rs) const
{
	std::cout << "'Less than' comparison operator called" << std::endl;
	if (this->value < rs.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator>(const Fixed& rs) const
{
	std::cout << "'More than' comparison operator called" << std::endl;
	if (this->value > rs.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator<=(const Fixed& rs) const
{
	std::cout << "'Less or equal to' comparison operator called" << std::endl;
	if (this->value <= rs.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator>=(const Fixed& rs) const
{
	std::cout << "'More or equal to' comparison operator called" << std::endl;
	if (this->value >= rs.getRawBits())
		return (true);
	else
		return (false);
}


/* Arithmetic operator functions */

Fixed Fixed::operator+(const Fixed& rs)
{
	Fixed result;

	std::cout << "Addition arithmetic operator called" << std::endl;
	result.setRawBits(this->value + rs.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed& rs)
{
	Fixed result;

	std::cout << "Subtration arithmetic operator called" << std::endl;
	result.setRawBits(this->value + rs.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed& rs)
{
	Fixed result;
	long long aux;

	std::cout << "Multiplication arithmetic operator called" << std::endl;
	aux = (long long)this->value * (long long)rs.getRawBits();
	aux = (aux >> this->fraction) & INT_MAX;
	std::cout << aux << std::endl;
	result.setRawBits(aux);
	return (result);
}

Fixed Fixed::operator/(const Fixed& rs)
{
	Fixed result;
	long long aux;

	std::cout << "Division arithmetic operator called" << std::endl;
	aux = (long long)this->value << this->fraction / rs.getRawBits();
	aux = (aux >> this->fraction) & INT_MAX;
	std::cout << aux << std::endl;
	result.setRawBits(aux);
	return (result);
}


/* Increment and decrement operators. The ones getting no parameter and
 * returning the instance are for prefix, the ones getting an int as parameter
 * and returning a copy are for sufix */

Fixed& Fixed::operator++(void)
{
	std::cout << "Prefix increment operator called" << std::endl;
	this->value = this->value + 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed aux(*this);

	std::cout << "Sufix increment operator called" << std::endl;
	this->value = this->value + 1;
	return (aux);
}

Fixed& Fixed::operator--(void)
{
	std::cout << "Prefix decrement operator called" << std::endl;
	this->value = this->value - 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed aux(*this);

	std::cout << "Sufix decrement operator called" << std::endl;
	this->value = this->value - 1;
	return (aux);
}


/* Getter and setter */

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}


/* Type conversion Functions */

float Fixed::toFloat(void) const
{
	std::cout << "toFloat member function called" << std::endl;
	return (this->value / (float)(1 << this->fraction));
}

int Fixed::toInt(void) const
{
	std::cout << "toInt member function called" << std::endl;
	return(this->value >> this->fraction);
}


/* Static class functions. Return the bigger or smaller of the two parameters
 * passed */

Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
	std::cout << "Min static class member function called" << std::endl;
	if (f1.getRawBits() <= f2.getRawBits())
		return(f1);
	else
		return(f2);
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
	std::cout << "Min static class member function called for consts" << std::endl;
	if (f1.getRawBits() <= f2.getRawBits())
		return(f1);
	else
		return(f2);
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
	std::cout << "Max static class member function called" << std::endl;
	if (f1.getRawBits() >= f2.getRawBits())
		return(f1);
	else
		return(f2);
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
	std::cout << "Max static class member function called for consts" << std::endl;
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
