
#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <iostream>
#include <vector>
#include "rt2d/color.h"

class Sequence{
public:
	Sequence();
	virtual ~Sequence();
	virtual void update(float deltaTime);
  void nextElementInVector();
	bool correctSequence(int id);
	int getElementAtIndex(int _index);

	bool isDone();

	int index;
	int lives;
  std::vector<int> order;
private:

};

#endif /* SEQUENCE_H */
