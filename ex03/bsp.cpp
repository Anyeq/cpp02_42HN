/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 14:19:38 by asando            #+#    #+#             */
/*   Updated: 2026/06/29 15:12:53 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float	area(Point const a, Point const b, Point const c) {
	return (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())
			+ b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())
			+ c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()))
		/ 2.0f;
}

bool	bsp(Point const a, Point const b, Point const c, Point const p) {
	float	A = area(a, b, c);
	float	A1 = area(p, b, c);
	float	A2 = area(a, p, c);
	float	A3 = area(a, b, p);

	if (A < 0) {
		A = -A;
		A1 = -A1;
		A2 = -A2;
		A3 = -A3;
	}

	return (A1 > 0 && A2 > 0 && A3 > 0 && (A1 + A2 + A3) <= A);
}
