/*
 * Utils.h
 *
 *  Created on: 25 de mar de 2016
 *      Author: cassiano
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>

#include <SFML/Graphics.hpp>

bool pointInsideRect(const sf::FloatRect& rect, const sf::Vector2f& point) {
//	printf("(%.2f, %.2f, %.2f, %.2f) (%.2f, %.2f)\n", rect.left, rect.top, rect.left + rect.width, rect.top + rect.height, point.x, point.y);

	if ((rect.left < point.x) && (rect.top < point.y)
			&& (point.x < (rect.left + rect.width))
			&& (point.y < (rect.top + rect.height))) {
		return true;
	}

	return false;
}

#endif /* UTILS_H_ */
