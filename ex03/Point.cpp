/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 01:04:45 by psmolin           #+#    #+#             */
/*   Updated: 2025/09/21 00:20:00 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point () : x(Fixed(0)), y(Fixed(0)) {};

Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)) {};

Point::Point (const Point &other) : x(other.getX()), y(other.getY()) {};

Point &Point::operator = (const Point &other)
{
	// essentially just for the compiler, as x and y are const
	// Just to comply with the orthodox canonical form
	(void)other;
	return (*this);
};

Point::~Point () {};

Fixed		Point::getX(void) const {return (this->x);};
Fixed		Point::getY(void) const {return (this->y);};

