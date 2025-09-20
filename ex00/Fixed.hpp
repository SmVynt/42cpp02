/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 01:04:50 by psmolin           #+#    #+#             */
/*   Updated: 2025/09/20 17:54:21 by psmolin          ###   ########.fr       */
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
		Fixed(const Fixed &other);
		Fixed &operator = (const Fixed &other);
		~Fixed();
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
	private:
		static const int	fractionalBits = 8;
		int					rawBits;
};

#endif
