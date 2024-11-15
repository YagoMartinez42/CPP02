/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:06:33 by samartin          #+#    #+#             */
/*   Updated: 2024/11/15 11:29:56 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c( 42.42f );
	Fixed const d( -1 );
	float n = 3.001f;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << std::endl;
	std::cout << "Custom tests" << std::endl;
	a.setRawBits( 123443 );
	std::cout << "a is " << a << std::endl;
	std::cout << "a two lowest weight bits are: " << ((a.getRawBits() & 2) >> 1) << (a.getRawBits() & 1) << std::endl;
	a++;
	std::cout << "after ++, a two lowest weight bits are: " << ((a.getRawBits() & 2) >> 1) << (a.getRawBits() & 1) << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "b raw integer decimal representation is: " << b.getRawBits() << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "c raw integer decimal representation is: " << c.getRawBits() << std::endl;
	c--;
	std::cout << "after --, c raw integer decimal representation is: " << c.getRawBits() << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d << " as decimal with point and " << d.toInt() << " as integer." << std::endl;

	std::cout << "is a greater than b? ";
	if (a > b)
		std::cout << "yes";
	else
		std::cout << "no";
	std::cout << std::endl;
	std::cout << "is b equal or greater than c? ";
	if (b >= c)
		std::cout << "yes";
	else
		std::cout << "no";
	std::cout << std::endl;
	std::cout << "is a less than c? ";
	if (a < c)
		std::cout << "yes";
	else
		std::cout << "no";
	std::cout << std::endl;
	std::cout << "is c equal or less than d? ";
	if (c <= d)
		std::cout << "yes";
	else
		std::cout << "no";
	std::cout << std::endl;
	std::cout << "is b equal to d? ";
	if (b == d)
		std::cout << "yes";
	else
		std::cout << "no";
	std::cout << std::endl;
	std::cout << "is a different to d? ";
	if (a != d)
		std::cout << "yes";
	else
		std::cout << "no";
	std::cout << std::endl;
	std::cout << "At this point of the test:" << std::endl;
	std::cout << "a = " << a << " b = " << b << " c = " << c << " d = " << d << std::endl;
	std::cout << "a + b is " << (a + b) << std::endl;
	std::cout << "c - d is " << (c - d) << std::endl;
	std::cout << "a * c is " << (a * c) << std::endl;
	std::cout << "b * c is " << (b * c) << std::endl;
	std::cout << "a / b is " << (a / b) << std::endl;
	std::cout << "b / d is " << (b / d) << std::endl;
	std::cout << "Float control example as a curiosity" << std::endl;
	std::cout << "n is " << n << std::endl;
	n++;
	std::cout << "after ++, n is " << n << std::endl;
	return 0;
}
