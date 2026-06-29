/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 14:19:19 by asando            #+#    #+#             */
/*   Updated: 2026/06/29 15:14:55 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main(void) {
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(0.0f, 10.0f);

	Point inside(2.0f, 2.0f);
	Point outside(20.0f, 20.0f);

	std::cout << "Inside? " << bsp(a, b, c, inside) << std::endl;
	std::cout << "Outside? " << bsp(a, b, c, outside) << std::endl;

	return 0;
}
