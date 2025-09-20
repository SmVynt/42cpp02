/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 01:04:50 by psmolin           #+#    #+#             */
/*   Updated: 2025/09/20 19:13:46 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# define COL_R	"\033[31m"
# define COL_Y	"\033[33m"
# define COL_B	"\033[34m"
# define COL_X	"\033[0m"

class Fixed
{
	public:
		Fixed();
		Fixed(const int raw);
		Fixed(const float raw);
		Fixed(const Fixed &other);
		~Fixed();

		// Assignment
		Fixed	&operator = (const Fixed &other);

		// Comparison
		bool	operator > (const Fixed &other) const;
		bool	operator < (const Fixed &other) const;
		bool	operator >= (const Fixed &other) const;
		bool	operator <= (const Fixed &other) const;
		bool	operator == (const Fixed &other) const;
		bool	operator != (const Fixed &other) const;

		// Math
		Fixed	operator + (const Fixed &other) const;
		Fixed	operator - (const Fixed &other) const;
		Fixed	operator * (const Fixed &other) const;
		Fixed	operator / (const Fixed &other) const;

		Fixed	&operator ++ ();
		Fixed	operator ++ (int);
		Fixed	&operator -- ();
		Fixed	operator -- (int);

		static Fixed		&min (Fixed &a, Fixed &b);
		static const Fixed	&min (const Fixed &a, const Fixed &b);
		static Fixed		&max (Fixed &a, Fixed &b);
		static const Fixed	&max (const Fixed &a, const Fixed &b);

		// Bits
		int					getRawBits(void) const;
		void				setRawBits(int const raw);

		// Conversions
		float				toFloat(void) const;
		int					toInt(void) const;

	private:
		static const int	fractionalBits = 8;
		int					rawBits;
};

std::ostream &operator << (std::ostream &out, const Fixed &fixed);

#endif
