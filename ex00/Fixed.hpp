/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:06:51 by samartin          #+#    #+#             */
/*   Updated: 2024/03/21 15:47:13 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	private:
		int value;
		static const int fraction = 8;
	public:
		Fixed(void);
		Fixed(const Fixed & orig);
		~Fixed(void);
		Fixed& operator=(const Fixed & val);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif