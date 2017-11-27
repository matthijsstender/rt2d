
#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <iostream>
#include "rt2d/color.h"
#include <vector>
#include "button.h"
#include <time.h>

class Sequence{
public:
	Sequence(std::vector<MyEntity*> b);
	virtual ~Sequence();

	virtual void update(float deltaTime);

  void randomSequence();
  void play();

private:
  std::vector<MyEntity*> buttons;
  std::vector<int> order;
  int c;
  
};

#endif /* SEQUENCE_H */
