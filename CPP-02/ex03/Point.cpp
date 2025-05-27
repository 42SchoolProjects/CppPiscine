/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:51:48 by albillie          #+#    #+#             */
/*   Updated: 2025/02/13 01:44:23 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

Point::Point() : x(0),  y(0)
{

}

Point::Point(const float x, const float y) : x(x), y(y)
{

}

Point::Point(const Point &point) : x(point.x), y(point.y)
{

}

Point &Point::operator=(const Point)
{
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

Point::~Point()
{

}

// Setters
Fixed Point::getX() const
{
	return (this->x);
}

Fixed Point::getY() const
{
	return (this->y);
}

// Algorithm
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed const x = point.getX();
	Fixed const y = point.getY();
	Fixed const x1 = a.getX();
	Fixed const y1 = a.getY();
	Fixed const x2 = b.getX();
	Fixed const y2 = b.getY();
	Fixed const x3 = c.getX();
	Fixed const y3 = c.getY();
	Fixed const x1y1 = (x1 - x) * (y2 - y1) - (x2 - x1) * (y1 - y);
	Fixed const x2y2 = (x2 - x) * (y3 - y2) - (x3 - x2) * (y2 - y);
	Fixed const x3y3 = (x3 - x) * (y1 - y3) - (x1 - x3) * (y3 - y);

	if (x1y1 > 0 && x2y2 > 0 && x3y3 > 0)
		return true;
	if (x1y1 < 0 && x2y2 < 0 && x3y3 < 0)
		return true;
	return false;
}

