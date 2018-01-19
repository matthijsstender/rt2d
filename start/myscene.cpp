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
	std::vector<Button*> buttons = std::vector<Button*>();
	startSeq = true;

	// create a single instance of Button in the middle of the screen.
	// the Sprite is added in Constructor of Button.
	buttonr = new Button(RGBAColor(255,0,0,127), 0);
	std::cout << "buttonr id: " << buttonr->id << '\n';
	buttonr->position = Point2(W - 128,H - 128);
	buttong = new Button(RGBAColor(0,255,0,127), 1);
	std::cout << "buttong id: " << buttong->id << '\n';
	buttong->position = Point2(W - 128,H + 128);
	buttonb = new Button(RGBAColor(0,0,255,127), 2);
	std::cout << "buttonb id: " << buttonb->id << '\n';
	buttonb->position = Point2(W + 128,H - 128);
	buttony = new Button(RGBAColor(255,255,0,127), 3);
	std::cout << "buttony id: " << buttony->id << '\n';
	buttony->position = Point2(W + 128,H + 128);

	hsCounter = 0;
	lives = new Text();
	lives->scale = Point2(0.5f, 0.5f);
	lives->position = Point2(W*1.5, H/4);
	hs = new Text();
	hs->scale = Point2(0.5f, 0.5f);
	hs->position = Point2(W/4, H/4);

	allButtons.push_back(buttonr);
	allButtons.push_back(buttong);
	allButtons.push_back(buttonb);
	allButtons.push_back(buttony);

	buttong->rotation.z = -HALF_PI;
	buttonb->rotation.z = HALF_PI;
	buttony->rotation.z = PI;
	// create the scene 'tree'
	// add Button to this Scene as a child.
	this->addChild(buttonr);
	this->addChild(buttong);
	this->addChild(buttonb);
	this->addChild(buttony);
	this->addChild(hs);
	this->addChild(lives);
	seq = new Sequence();
	playGame();
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(buttonr);
	this->removeChild(buttong);
	this->removeChild(buttonb);
	this->removeChild(buttony);
	this->removeChild(hs);
	this->removeChild(lives);

	// delete Button from the heap (there was a 'new' in the constructor)
	delete buttonr;
	delete buttong;
	delete buttonb;
	delete buttony;
	delete hs;
	delete lives;
}
void MyScene::clearAllButtons() {
	buttonr->clear();
	buttong->clear();
	buttonb->clear();
	buttony->clear();
}
void MyScene::playGame() {
	seq->nextElementInVector();
	startSeq = true;
	currentSeq = 0;
	t.start();
}
void MyScene::update(float deltaTime)
{
	hs->message("Highscore: " + std::to_string(hsCounter));
	lives->message("Lives: " + std::to_string(seq->lives));
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	if(startSeq && t.seconds() > 1.2f){
		t.start();
		allButtons[seq->order[currentSeq]]->press();
		currentSeq++;
		if(currentSeq >= seq->order.size()){
			startSeq = false;
		}
	}

	if (t.seconds() > 0.7f) {
		if (buttonr->sprite()->color == RGBAColor(255,0,0,255)) {
			buttonr->sprite()->color = RGBAColor(255,0,0,127);
		}else if (buttong->sprite()->color == RGBAColor(0,255,0,255)) {
			buttong->sprite()->color = RGBAColor(0,255,0,127);
		}else if (buttonb->sprite()->color == RGBAColor(0,0,255,255)) {
			buttonb->sprite()->color = RGBAColor(0,0,255,127);
		}else if (buttony->sprite()->color == RGBAColor(255,255,0,255)) {
			buttony->sprite()->color = RGBAColor(255,255,0,127);
		}
	}

	if(!startSeq) {
		if(input()->getKeyDown(81) && seq->correctSequence(buttonr->id)) {
			// start the timer.
			t.start();
			clearAllButtons();
			buttonr->press();
		}else if(input()->getKeyDown(65) && seq->correctSequence(buttong->id)) {
			// start the timer.
			t.start();
			clearAllButtons();
			buttong->press();
		}else if(input()->getKeyDown(87) && seq->correctSequence(buttonb->id)) {
			// start the timer.
			t.start();
			clearAllButtons();
			buttonb->press();
		}else if(input()->getKeyDown(83) && seq->correctSequence(buttony->id)) {
			// start the timer.
			t.start();
			clearAllButtons();
			buttony->press();
		}
	}

	if(seq->isDone()){
		if (seq->order.size() == 0) {
			std::cout << "wrongerino" << '\n';
			hsCounter = 0;
			this->playGame();
		} else {
			std::cout << "correctemundo" << '\n';
			hsCounter++;
			this->playGame();
		}
	}

	// ###############################################################
	// Spacebar scales Button
	// ###############################################################
	/*if (input()->getKeyDown(KeyCode::Space)) {
		Button->scale = Point(0.5f, 0.5f);
	}
	if (input()->getKeyUp(KeyCode::Space)) {
		Button->scale = Point(1.0f, 1.0f);
	}*/
}
