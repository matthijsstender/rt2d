/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "myscene.h"

MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();
	float W = SWIDTH/4;
	float H = SHEIGHT/4;

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	myentityr = new MyEntity();
	myentityr->position = Point2(W,H);
	myentityg = new MyEntity();
	myentityg->position = Point2(W,H*3);
	myentityb = new MyEntity();
	myentityb->position = Point2(W*3,H);
	myentityy = new MyEntity();
	myentityy->position = Point2(W*3,H*3);

	myentityr->addSprite("assets/button.tga");
	myentityr->sprite()->color = RGBAColor(255,0,0,127);
	myentityg->addSprite("assets/button.tga");
	myentityg->sprite()->color = RGBAColor(0,255,0,127);
	myentityg->rotation.z = -HALF_PI;
	myentityb->addSprite("assets/button.tga");
	myentityb->sprite()->color = RGBAColor(0,0,255,127);
	myentityb->rotation.z = HALF_PI;
	myentityy->addSprite("assets/button.tga");
	myentityy->sprite()->color = RGBAColor(255,255,0,127);
	myentityy->rotation.z = PI;

	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(myentityr);
	this->addChild(myentityg);
	this->addChild(myentityb);
	this->addChild(myentityy);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(myentityr);
	this->removeChild(myentityg);
	this->removeChild(myentityb);
	this->removeChild(myentityy);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete myentityr;
	delete myentityg;
	delete myentityb;
	delete myentityy;
}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	// ###############################################################
	// Spacebar scales myentity
	// ###############################################################
	/*if (input()->getKeyDown(KeyCode::Space)) {
		myentity->scale = Point(0.5f, 0.5f);
	}
	if (input()->getKeyUp(KeyCode::Space)) {
		myentity->scale = Point(1.0f, 1.0f);
	}*/
}
