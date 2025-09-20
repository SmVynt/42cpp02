/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:51:32 by psmolin           #+#    #+#             */
/*   Updated: 2025/09/21 00:35:44 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main()
{
	// const Point	a(0.0f, 0.0f);
	// const Point	b(3.0f, 0.0f);
	// const Point	c(0.0f, 5.0f);
	// const Point	d(1.0f, 1.0f);
	// const Point	a(1.0f, 3.0f);
	// const Point	b(3.0f, 5.0f);
	// const Point	c(4.0f, 1.0f);
	// const Point	d(3.0f, 4.0f);
	const Point	a(0.0f, 1.0f);
	const Point	b(4.0f, -1.0f);
	const Point	c(2.0f, -3.0f);
	const Point	d(2.0f, -1.0f);
	bool	res = bsp(b, a, c, d);
	if (res)
		std::cout << "The point is inside" << std::endl;
	else
		std::cout << "The point is outside" << std::endl;

	return (0);
}

