/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */


#include "myscene.h"

MyScene::MyScene() : Scene()
{
	W = SWIDTH/2;
	H = SHEIGHT/2;
	std::vector<Button*> buttons = std::vector<Button*>();
	startSeq = true;
	pause = false;

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

	this->whichButton = 0;

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
	whichButton = 0;
}
void MyScene::playGame() {
	seq->nextElementInVector();
	startSeq = true;
	currentSeq = 0;
	t.start();
}
void MyScene::checkButtonMouse() {
	if (input()->getMouseDown(0) && !pause) {
		std::cout << "H: " << H << "W: " << W << '\n';
		//if(input()->getMouseX() < (W,H + 256) && input()->getMouseY() < (W,H + 256)) {
			if(input()->getMouseX() < W && input()->getMouseY() < H) {
				std::cout << "linksboven" << '\n';
				this->whichButton = 1;
			}else if(input()->getMouseX() < W && input()->getMouseY() > H) {
				std::cout << "linksonder" << '\n';
				this->whichButton = 2;
			}else if(input()->getMouseX() > W && input()->getMouseY() < H) {
				std::cout << "rechtsboven" << '\n';
				this->whichButton = 3;
			}else if(input()->getMouseX() > W && input()->getMouseY() > H) {
				std::cout << "rechtsonder" << '\n';
				this->whichButton = 4;
			}
		//}
	}
}
void MyScene::update(float deltaTime)
{
	this->whichButton = 0;
	checkButtonMouse();
	hs->message("Highscore: " + std::to_string(hsCounter));
	lives->message("Lives: " + std::to_string(seq->lives));
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	if(startSeq && t.seconds() > 1.2f){
		allButtons[seq->order[currentSeq]]->press();
		currentSeq++;
		if(currentSeq >= seq->order.size()){
			startSeq = false;
		}
		t.start();
	}

	if (t.seconds() > 0.7f) {
		if (buttonr->sprite()->color == RGBAColor(255,0,0,255)) {
			buttonr->sprite()->color = RGBAColor(255,0,0,127);
			whichButton = 0;
			pause = false;
		}else if (buttong->sprite()->color == RGBAColor(0,255,0,255)) {
			buttong->sprite()->color = RGBAColor(0,255,0,127);
			whichButton = 0;
			pause = false;
		}else if (buttonb->sprite()->color == RGBAColor(0,0,255,255)) {
			buttonb->sprite()->color = RGBAColor(0,0,255,127);
			whichButton = 0;
			pause = false;
		}else if (buttony->sprite()->color == RGBAColor(255,255,0,255)) {
			buttony->sprite()->color = RGBAColor(255,255,0,127);
			whichButton = 0;
			pause = false;
		}
	}

	if(!startSeq) {
		if((input()->getKeyDown(81) && seq->correctSequence(buttonr->id)) || (whichButton == 1 && seq->correctSequence(buttonr->id))) {
			pause = true;
			// start the timer.
			t.start();
			clearAllButtons();
			buttonr->press();
		}else if((input()->getKeyDown(65) && seq->correctSequence(buttong->id)) || (whichButton == 2 && seq->correctSequence(buttong->id))) {
			pause = true;
			// start the timer.
			t.start();
			clearAllButtons();
			buttong->press();
		}else if((input()->getKeyDown(87) && seq->correctSequence(buttonb->id)) || (whichButton == 3 && seq->correctSequence(buttonb->id))) {
			pause = true;
			// start the timer.
			t.start();
			clearAllButtons();
			buttonb->press();
		}else if((input()->getKeyDown(83) && seq->correctSequence(buttony->id)) || (whichButton == 4 && seq->correctSequence(buttony->id))) {
			pause = true;
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
