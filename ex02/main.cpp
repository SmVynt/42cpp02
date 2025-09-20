/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:51:32 by psmolin           #+#    #+#             */
/*   Updated: 2025/09/20 19:45:11 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main()
{
	// Test 1: Constructors
	std::cout << "\n--- Constructor Tests ---" << std::endl;
	Fixed a;				// Default constructor
	Fixed b(42);			// Int constructor
	Fixed c(42.42f);		// Float constructor
	Fixed d(c);				// Copy constructor

	std::cout << "Default (a): " << a << std::endl;
	std::cout << "Int 42 (b): " << b << std::endl;
	std::cout << "Float 42.42 (c): " << c << std::endl;
	std::cout << "Copy of c (d): " << d << std::endl;

	// Test 2: Assignment operator
	std::cout << "\n--- Assignment Operator Test ---" << std::endl;
	Fixed e;
	e = c;
	std::cout << "e = c: " << e << std::endl;

	// Test 3: Comparison operators
	std::cout << "\n--- Comparison Operators ---" << std::endl;
	Fixed x(10.5f);
	Fixed y(10.5f);
	Fixed z(5.25f);

	std::cout << "x = " << x << ", y = " << y << ", z = " << z << std::endl;
	std::cout << "x > z: " << (x > z) << " (should be 1)" << std::endl;
	std::cout << "x < z: " << (x < z) << " (should be 0)" << std::endl;
	std::cout << "x >= y: " << (x >= y) << " (should be 1)" << std::endl;
	std::cout << "x <= y: " << (x <= y) << " (should be 1)" << std::endl;
	std::cout << "x == y: " << (x == y) << " (should be 1)" << std::endl;
	std::cout << "x != z: " << (x != z) << " (should be 1)" << std::endl;

	// Test 4: Arithmetic operators
	std::cout << "\n--- Arithmetic Operators ---" << std::endl;
	Fixed num1(5.05f);
	Fixed num2(2.0f);

	std::cout << "num1 = " << num1 << ", num2 = " << num2 << std::endl;
	std::cout << "num1 + num2 = " << (num1 + num2) << " (should be ~7.05)" << std::endl;
	std::cout << "num1 - num2 = " << (num1 - num2) << " (should be ~3.05)" << std::endl;
	std::cout << "num1 * num2 = " << (num1 * num2) << " (should be ~10.1)" << std::endl;
	std::cout << "num1 / num2 = " << (num1 / num2) << " (should be ~2.525)" << std::endl;

	// Test 5: More complex arithmetic
	std::cout << "\n--- Complex Arithmetic ---" << std::endl;
	Fixed big(100.75f);
	Fixed small(0.25f);

	std::cout << "big = " << big << ", small = " << small << std::endl;
	std::cout << "big * small = " << (big * small) << " (should be ~25.1875)" << std::endl;
	std::cout << "big / small = " << (big / small) << " (should be 403)" << std::endl;

	// Test 6: Increment/Decrement operators
	std::cout << "\n--- Increment/Decrement Operators ---" << std::endl;
	Fixed counter(5.0f);
	std::cout << "Initial counter: " << counter << std::endl;
	std::cout << "++counter: " << ++counter << " (should be ~5.00391)" << std::endl;
	std::cout << "counter after pre-increment: " << counter << std::endl;
	std::cout << "counter++: " << counter++ << " (should show ~5.00391)" << std::endl;
	std::cout << "counter after post-increment: " << counter << " (should be ~5.00781)" << std::endl;

	std::cout << "--counter: " << --counter << " (should be ~5.00391)" << std::endl;
	std::cout << "counter--: " << counter-- << " (should show ~5.00391)" << std::endl;
	std::cout << "counter after post-decrement: " << counter << " (should be 5)" << std::endl;

	// Test 7: Min/Max functions
	std::cout << "\n--- Min/Max Static Functions ---" << std::endl;
	Fixed val1(10.5f);
	Fixed val2(15.25f);
	const Fixed cval1(7.75f);
	const Fixed cval2(12.5f);

	std::cout << "val1 = " << val1 << ", val2 = " << val2 << std::endl;
	std::cout << "min(val1, val2) = " << Fixed::min(val1, val2) << " (should be 10.5)" << std::endl;
	std::cout << "max(val1, val2) = " << Fixed::max(val1, val2) << " (should be 15.25)" << std::endl;

	std::cout << "cval1 = " << cval1 << ", cval2 = " << cval2 << std::endl;
	std::cout << "min(cval1, cval2) = " << Fixed::min(cval1, cval2) << " (should be 7.75)" << std::endl;
	std::cout << "max(cval1, cval2) = " << Fixed::max(cval1, cval2) << " (should be 12.5)" << std::endl;

	// Test 8: Edge cases
	std::cout << "\n--- Edge Cases ---" << std::endl;
	Fixed zero(0.0f);
	Fixed negative(-5.5f);
	Fixed verySmall(0.00390625f);  // 1/256, smallest representable value

	std::cout << "Zero: " << zero << std::endl;
	std::cout << "Negative: " << negative << std::endl;
	std::cout << "Very small (1/256): " << verySmall << std::endl;
	std::cout << "Negative + Positive: " << (negative + Fixed(10.0f)) << " (should be 4.5)" << std::endl;

	// Test 9: Conversion accuracy
	std::cout << "\n--- Conversion Accuracy ---" << std::endl;
	Fixed precise(3.141592f);
	std::cout << "Pi approximation: " << precise << std::endl;
	std::cout << "As int: " << precise.toInt() << " (should be 3)" << std::endl;

	return (0);
}

