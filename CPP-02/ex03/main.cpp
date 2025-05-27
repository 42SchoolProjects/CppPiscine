/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:42:24 by albillie          #+#    #+#             */
/*   Updated: 2025/02/13 01:43:43 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

int	main()
{
	Point a( 0,0 );
	Point b( 20,0 );
	Point c( 10,30 );
	Point point( 10, 15);

	if (!bsp(a, b, c, point))
		std::cout << "Point is not inside triangle" << std::endl;
	else
		std::cout << "Point is inside the triangle" << std::endl;
	Point point2(30,15);
	if (!bsp(a, b, c, point2))
		std::cout << "Point is not inside triangle" << std::endl;
	else
		std::cout << "Point is inside the triangle" << std::endl;
	Point point3(10, 30);
	if (!bsp(a, b, c, point3))
		std::cout << "Point is not inside triangle" << std::endl;
	else                                                                                                                                                                                                                                      
		std::cout << "Point is inside the triangle" << std::endl;
}
