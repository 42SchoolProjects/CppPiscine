/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:52:02 by albillie          #+#    #+#             */
/*   Updated: 2025/02/13 00:09:16 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const	y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &Point);
		~Point();
		Point &operator=(const Point);
		Fixed 	getY() const;
		Fixed 	getX() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
