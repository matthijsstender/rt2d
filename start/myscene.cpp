/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */


#include "myscene.h"

MyScene::MyScene() : Scene()
{
	float W = SWIDTH/2;
	float H = SHEIGHT/2;
	std::vector<MyEntity*> buttons = std::vector<MyEntity*>();
	startSeq = true;

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	buttonr = new MyEntity(RGBAColor(255,0,0,127));
	buttonr->position = Point2(W - 128,H - 128);
	buttong = new MyEntity(RGBAColor(0,255,0,127));
	buttong->position = Point2(W- 128,H + 128);
	buttonb = new MyEntity(RGBAColor(0,0,255,127));
	buttonb->position = Point2(W + 128,H - 128);
	buttony = new MyEntity(RGBAColor(255,255,0,127));
	buttony->position = Point2(W + 128,H + 128);

	buttons.push_back(buttonr);
	buttons.push_back(buttong);
	buttons.push_back(buttonb);
	buttons.push_back(buttony);

	buttong->rotation.z = -HALF_PI;
	buttonb->rotation.z = HALF_PI;
	buttony->rotation.z = PI;
	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(buttonr);
	this->addChild(buttong);
	this->addChild(buttonb);
	this->addChild(buttony);
	seq = new Sequence(buttons);
	play();
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(buttonr);
	this->removeChild(buttong);
	this->removeChild(buttonb);
	this->removeChild(buttony);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete buttonr;
	delete buttong;
	delete buttonb;
	delete buttony;
}
void MyScene::play() {
  if (startSeq == true) {
    seq->randomSequence();
		t.start();
  }
}
void MyScene::clearAllButtons() {
	buttonr->clear();
	buttong->clear();
	buttonb->clear();
	buttony->clear();
}
void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
	if (t.seconds() > 0.7f) {
		if (startSeq == true) {
			play();
			startSeq = false;
		}
		if (buttonr->sprite()->color == RGBAColor(255,0,0,255)) {
			buttonr->sprite()->color = RGBAColor(255,0,0,127);
		}
		if (buttong->sprite()->color == RGBAColor(0,255,0,255)) {
			buttong->sprite()->color = RGBAColor(0,255,0,127);
		}
		if (buttonb->sprite()->color == RGBAColor(0,0,255,255)) {
			buttonb->sprite()->color = RGBAColor(0,0,255,127);
		}
		if (buttony->sprite()->color == RGBAColor(255,255,0,255)) {
			buttony->sprite()->color = RGBAColor(255,255,0,127);
		}
	}
	if(startSeq == false) {
		if(input()->getKeyDown(81)) {
			// start the timer.
			t.start();
			std::cout << "pressed q" << '\n';
			clearAllButtons();
			buttonr->press();

		}
		if(input()->getKeyDown(65)) {
			// start the timer.
			t.start();
			std::cout << "pressed a" << '\n';
			clearAllButtons();
			buttong->press();
		}
		if(input()->getKeyDown(87)) {
			// start the timer.
			t.start();
			std::cout << "pressed w" << '\n';
			clearAllButtons();
			buttonb->press();
		}
		if(input()->getKeyDown(83)) {
			// start the timer.
			t.start();
			std::cout << "pressed s" << '\n';
			clearAllButtons();
			buttony->press();
		}
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
