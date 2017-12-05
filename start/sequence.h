
#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <iostream>
#include <vector>
#include <time.h>
#include "button.h"
#include "rt2d/color.h"

class Sequence{
public:
	Sequence(std::vector<Button*> b);
	virtual ~Sequence();

	virtual void update(float deltaTime);

  void randomSequence();
  void play();
	bool correctSequence(Button* bt);
	int index;
  std::vector<int> order;
	std::vector<Button*> buttons;
  Button* b;
private:

};

#endif /* SEQUENCE_H */
