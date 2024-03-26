/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:06:51 by samartin          #+#    #+#             */
/*   Updated: 2024/03/26 16:05:58 by samartin         ###   ########.fr       */
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
		Fixed(const Fixed & orig);
		Fixed(const int & intnum);
		Fixed(const float & floatnum);
		~Fixed(void);
		Fixed & operator=(const Fixed & val);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream & operator<<(std::ostream & stm, const Fixed & val);

#endif