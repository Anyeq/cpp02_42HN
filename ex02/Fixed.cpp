/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 11:07:17 by asando            #+#    #+#             */
/*   Updated: 2026/06/28 17:26:25 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

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

Fixed	Fixed::operator+(const Fixed& rhs) const {
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(const Fixed& rhs) const {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(const Fixed& rhs) const {
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed& rhs) const {
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed&	Fixed::operator++() {
	_rawBits++;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	temp(*this);
	_rawBits++;
	return temp;
}

Fixed&	Fixed::operator--() {
	_rawBits--;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed	temp(*this);
	_rawBits--;
	return temp;
}

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	if (a > b)
		return b;
	return a;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	if (a > b)
		return (b);
	return (a);
}


Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	if (a > b)
		return a;
	return b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	if (a > b)
		return (a);
	return (b);
}

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}
