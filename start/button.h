/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file Button.h
 *
 * @brief description of Button behavior.
 */

#ifndef Button_H
#define Button_H

#include <rt2d/entity.h>

/// @brief The Button class is the Entity implementation.
class Button : public Entity
{
public:
	/// @brief Constructor
	Button(RGBAColor c, int _id);
	/// @brief Destructor
	virtual ~Button();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	void press();
	void clear();
	RGBAColor getColor();
	int id;

private:
	/* add your private declarations */

	RGBAColor color;
};

#endif /* Button_H */
