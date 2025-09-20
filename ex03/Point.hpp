/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 01:04:50 by psmolin           #+#    #+#             */
/*   Updated: 2025/09/21 00:21:20 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

# define COL_R	"\033[31m"
# define COL_Y	"\033[33m"
# define COL_B	"\033[34m"
# define COL_X	"\033[0m"

class Point
{
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &other);
		Point &operator = (const Point &other);
		~Point();
		void		setX(const float x);
		void		setY(const float y);
		Fixed		getX(void) const;
		Fixed		getY(void) const;
	private:
		Fixed		x;
		Fixed		y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
