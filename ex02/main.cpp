/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:06:33 by samartin          #+#    #+#             */
/*   Updated: 2024/04/01 15:48:52 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
/*
int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}*/

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c( 42.42f );
	Fixed const d( 10 );
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
	a.setRawBits( 12344321);
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

	std::cout << "n is " << n << std::endl;
	n++;
	std::cout << "after ++, n is " << n << std::endl;
	return 0;
}
