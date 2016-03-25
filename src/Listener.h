/*
 * Listener.h
 *
 *  Created on: 25 de mar de 2016
 *      Author: cassiano
 */

#ifndef LISTENER_H_
#define LISTENER_H_

#include <SFML/Window.hpp>

class IClickListener {
public:
	virtual ~IClickListener() {}

	virtual bool onClickListener(const sf::Vector2f& position) = 0;
};



#endif /* LISTENER_H_ */
