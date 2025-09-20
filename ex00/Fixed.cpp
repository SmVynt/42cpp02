/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 01:04:45 by psmolin           #+#    #+#             */
/*   Updated: 2025/09/20 17:58:41 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed () : rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed (const Fixed &other) : rawBits(other.getRawBits()) {
	std::cout << "Copy constructor called" << std::endl;
};

Fixed &Fixed::operator = (const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		rawBits = other.getRawBits();
	return (*this);
};

Fixed::~Fixed (){
	std::cout << "Destructor called" << std::endl;
};

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->rawBits);
};

void	Fixed::setRawBits(int const raw) {
	this->rawBits = raw;
};

