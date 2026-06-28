/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 11:07:17 by asando            #+#    #+#             */
/*   Updated: 2026/06/28 12:41:59 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _rawBits(0) {}

Fixed::Fixed(const int value) {
	_rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
	_rawBits = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& rhs) {
	if (this != &rhs)
		_rawBits = rhs._rawBits;
	return *this;
}

Fixed::~Fixed() {}

int	Fixed::getRawBits(void) const {
	return _rawBits;
}

void	Fixed::setRawBits(int const raw) {
	_rawBits = raw;
}

float	Fixed::toFloat(void) const {
	return (float)_rawBits / (float)(1 << _fractionalBits);
}

int	Fixed::toInt(void) const {
	return _rawBits >> _fractionalBits;
}

bool	Fixed::operator>(const Fixed& rhs) const {
	return _rawBits > rhs._rawBits;
}

bool	Fixed::operator<(const Fixed& rhs) const {
	return _rawBits < rhs._rawBits;
}

bool	Fixed::operator>=(const Fixed& rhs) const {
	return _rawBits >= rhs._rawBits;
}

bool	Fixed::operator<=(const Fixed& rhs) const {
	return _rawBits <= rhs._rawBits;
}

bool	Fixed::operator==(const Fixed& rhs) const {
	return _rawBits == rhs._rawBits;
}

bool	Fixed::operator!=(const Fixed& rhs) const {
	return _rawBits != rhs._rawBits;
}
