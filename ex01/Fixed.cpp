/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 01:04:45 by psmolin           #+#    #+#             */
/*   Updated: 2025/09/20 18:32:21 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed () : rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed (const int raw){
	std::cout << "Int constructor called" << std::endl;
	rawBits = raw << fractionalBits;
};

Fixed::Fixed (const float raw){
	std::cout << "Float constructor called" << std::endl;
	rawBits = roundf(raw * (1 << fractionalBits));
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
	return (this->rawBits);
};

void	Fixed::setRawBits(int const raw) {
	this->rawBits = raw;
};


float	Fixed::toFloat(void) const {
	return ((float)rawBits / (1 << fractionalBits));
};

int		Fixed::toInt(void) const {
	return (rawBits >> fractionalBits);
};

std::ostream &operator << (std::ostream &out, const Fixed &fixed){
	out << fixed.toFloat();
	return (out);
};
