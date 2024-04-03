/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:06:51 by samartin          #+#    #+#             */
/*   Updated: 2024/04/02 11:55:59 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int value;
		static const int fraction = 8;
	public:
		Fixed(void);
		Fixed(const Fixed& orig);
		Fixed(const int& intnum);
		Fixed(const float& floatnum);
		~Fixed(void);
		Fixed& operator=(const Fixed& rs);
		bool operator==(const Fixed& rs) const;
		bool operator!=(const Fixed& rs) const;
		bool operator<(const Fixed& rs) const;
		bool operator>(const Fixed& rs) const;
		bool operator<=(const Fixed& rs) const;
		bool operator>=(const Fixed& rs) const;
		Fixed operator+(const Fixed& rs) const;
		Fixed operator-(const Fixed& rs) const;
		Fixed operator*(const Fixed& rs) const;
		Fixed operator/(const Fixed& rs) const;
		Fixed& operator++(void); //Prefix
		Fixed operator++(int); //Sufix
		Fixed& operator--(void); //Prefix
		Fixed operator--(int); //Sufix
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		static Fixed& min(Fixed& f1, Fixed& f2);
		static const Fixed& min(const Fixed& f1, const Fixed& f2);
		static Fixed& max(Fixed& f1, Fixed& f2);
		static const Fixed& max(const Fixed& f1, const Fixed& f2);
};

std::ostream& operator<<(std::ostream& stm, const Fixed& rs);

#endif