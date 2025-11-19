/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 23:50:54 by psmolin           #+#    #+#             */
/*   Updated: 2025/09/21 00:35:56 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	Area = Fixed(0.5f) *
		(a.getY() * (c.getX() - b.getX())
			+ a.getX() * (b.getY() - c.getY())
			+ (b.getX() * c.getY())
			- (b.getY() * c.getX()));
	if (Area == Fixed(0))
		return (false);
	Fixed	s = (a.getY() * c.getX()
				- a.getX() * c.getY()
				+ (c.getY() - a.getY()) * point.getX()
				+ (a.getX() - c.getX()) * point.getY())
					/ (Fixed(2) * Area);
	Fixed	t = (a.getX() * b.getY()
				- a.getY() * b.getX()
				+ (a.getY() - b.getY()) * point.getX()
				+ (b.getX() - a.getX()) * point.getY())
					/ (Fixed(2) * Area);
	if (s > Fixed(0) && t > Fixed(0) && (s + t) < Fixed(1))
		return (true);
	return (false);
};
