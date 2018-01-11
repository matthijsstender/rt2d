/**
 * This class describes Button behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "button.h"

Button::Button(RGBAColor c, int _id) : Entity()
{
	Audio::init();
	color = c;
	id = _id;
	std::cout << "id param: " << id << '\n';
	std::cout << "id value: " << this->id << '\n';
	this->addSprite("assets/button.tga");
	this->sprite()->color = color;

	rs = new Sound("assets/bleep_1.wav");
	gs = new Sound("assets/bleep_2.wav");
	bs = new Sound("assets/bleep_3.wav");
	ys = new Sound("assets/bleep_4.wav");
}

Button::~Button()
{

}

void Button::update(float deltaTime)
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

void Button::press(){
	RGBAColor c = color;
	c.a = 255;
	stopSounds();
	this->sprite()->color = c;
	if (this->id == 0) {
		rs->play();
	} else if (this->id == 1) {
		gs->play();
	}	else if (this->id == 2) {
		bs->play();
	} else if (this->id == 3) {
		ys->play();
	}
}

void Button::stopSounds(){
	rs->stop();
	gs->stop();
	bs->stop();
	ys->stop();
}

RGBAColor Button::getColor(){
	return this->color;
}

void Button::clear() {
	RGBAColor c = color;
	c.a = 127;
	this->sprite()->color = c;
}
