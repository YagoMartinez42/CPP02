/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:07:02 by samartin          #+#    #+#             */
/*   Updated: 2024/03/29 17:25:33 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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

Fixed& Fixed::operator=(const Fixed& rs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = rs.getRawBits();
	return (*this);
}

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

float Fixed::toFloat(void) const
{
	return (this->value / (float)(1 << this->fraction));
}

int Fixed::toInt(void) const
{
	return(this->value >> this->fraction);
}

std::ostream& operator<<(std::ostream & stm, const Fixed& rs)
{
	stm << rs.toFloat();
	return (stm);
}
