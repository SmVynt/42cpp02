/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 01:04:45 by psmolin           #+#    #+#             */
/*   Updated: 2025/09/20 19:38:15 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// CONSTUCTORS

Fixed::Fixed () : rawBits(0) {};

Fixed::Fixed (const int raw) {rawBits = raw << fractionalBits;};

Fixed::Fixed (const float raw) {
	rawBits = roundf(raw * (1 << fractionalBits));
};

Fixed::Fixed (const Fixed &other) : rawBits(other.getRawBits()) {};

Fixed::~Fixed () {};

// OPERATORS

Fixed &Fixed::operator = (const Fixed &other)
{
	if (this != &other)
		rawBits = other.getRawBits();
	return (*this);
};

bool	Fixed::operator > (const Fixed &other) const {
	return (rawBits > other.getRawBits());
};
bool	Fixed::operator < (const Fixed &other) const {
	return (rawBits < other.getRawBits());
};
bool	Fixed::operator >= (const Fixed &other) const {
	return (rawBits >= other.getRawBits());
};
bool	Fixed::operator <= (const Fixed &other) const {
	return (rawBits <= other.getRawBits());
};
bool	Fixed::operator == (const Fixed &other) const {
	return (rawBits == other.getRawBits());
};
bool	Fixed::operator != (const Fixed &other) const {
	return (rawBits != other.getRawBits());
};

// MATH

Fixed	Fixed::operator + (const Fixed &other) const {
	Fixed	res;
	res.setRawBits(rawBits + other.getRawBits());
	return (res);
};
Fixed	Fixed::operator - (const Fixed &other) const {
	Fixed	res;
	res.setRawBits(rawBits - other.getRawBits());
	return (res);
};
Fixed	Fixed::operator * (const Fixed &other) const {
	Fixed		res;
	long long	temp;
	temp = rawBits * other.getRawBits();
	temp >>= fractionalBits;
	res.setRawBits((int)temp);
	return (res);
};
Fixed	Fixed::operator / (const Fixed &other) const {
	Fixed		res;
	long long	temp;
	temp = ((long long)rawBits << fractionalBits) / other.getRawBits();
	res.setRawBits((int)temp);
	return (res);
};

Fixed	&Fixed::operator ++ () {
	rawBits++;
	return (*this);
};
Fixed	Fixed::operator ++ (int) {
	Fixed temp(*this);
	rawBits++;
	return (temp);
};
Fixed	&Fixed::operator -- () {
	rawBits--;
	return (*this);
};
Fixed	Fixed::operator -- (int) {
	Fixed temp(*this);
	rawBits--;
	return (temp);
};

Fixed	&Fixed::min (Fixed &a, Fixed &b) {
	return ((a.getRawBits() < b.getRawBits()) ? a : b);
};
const Fixed	&Fixed::min (const Fixed &a, const Fixed &b) {
	return ((a.getRawBits() < b.getRawBits()) ? a : b);
};
Fixed	&Fixed::max (Fixed &a, Fixed &b) {
	return ((a.getRawBits() > b.getRawBits()) ? a : b);
};
const Fixed	&Fixed::max (const Fixed &a, const Fixed &b) {
	return ((a.getRawBits() > b.getRawBits()) ? a : b);
};

// GET SET BITS

int		Fixed::getRawBits(void) const {
	return (this->rawBits);
};

void	Fixed::setRawBits(int const raw) {
	this->rawBits = raw;
};

// CONVERTORS

float	Fixed::toFloat(void) const {
	return ((float)rawBits / (1 << fractionalBits));
};

int		Fixed::toInt(void) const {
	return (rawBits >> fractionalBits);
};

// STREAM

std::ostream &operator << (std::ostream &out, const Fixed &fixed){
	out << fixed.toFloat();
	return (out);
};
