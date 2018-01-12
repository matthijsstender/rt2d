/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>
#include <rt2d/text.h>
#include <fstream>
#include <sstream>
#include <vector>

#include "button.h"
#include "sequence.h"

/// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene
{
public:
	/// @brief Constructor
	MyScene();
	/// @brief Destructor
	virtual ~MyScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	void clearAllButtons();
	void playGame();
private:
	Button* buttonr;
	Button* buttong;
	Button* buttonb;
	Button* buttony;

	std::vector<Button*> allButtons;

	Timer t;
	Text* hs;
	Text* lives;
	int hsCounter;
	Sequence* seq;
	bool startSeq;
	int currentSeq;
};

#endif /* SCENE00_H */
