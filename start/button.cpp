/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "button.h"

MyEntity::MyEntity(RGBAColor c) : Entity()
{
	color = c;

	this->addSprite("assets/button.tga");
	this->sprite()->color = color;
}

MyEntity::~MyEntity()
{

}

void MyEntity::update(float deltaTime)
{

	/*if(input()->getKey(262)){
		this->position.x+=5000.0*deltaTime;
	}
	if (this->position.x-(this->sprite()->size.x/2.0f)>SWIDTH) {
		this->position.x = - (this->sprite()->size.x/2.0f);
	}
	if(input()->getKey(263)) {
		this->position.x+=-5000.0*deltaTime;
	}
	if (this->position.x+(this->sprite()->size.x/2.0f)<0.0f) {
		this->position.x = SWIDTH + (this->sprite()->size.x/2.0f);
	}
	if(input()->getKey(264)) {
		this->position.y+=5000.0*deltaTime;
	}
	if (this->position.y-(this->sprite()->size.y/2.0f)>SHEIGHT) {
		this->position.y = - (this->sprite()->size.y/2.0f);
	}
	if(input()->getKey(265)) {
		this->position.y+=-5000.0*deltaTime;
	}
	if (this->position.y+(this->sprite()->size.y/2.0f)<0.0f) {
		this->position.y = SHEIGHT + (this->sprite()->size.y/2.0f);
	}*/
}

void MyEntity::press(){

	RGBAColor c = color;
	c.a = 255;

	this->sprite()->color = c;
}

RGBAColor MyEntity::getColor()
{
	return this->color;
}

void MyEntity::clear() {
	RGBAColor c = color;
	c.a = 127;

	this->sprite()->color = c;
}
