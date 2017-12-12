
#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <iostream>
#include <vector>
#include <time.h>
#include "rt2d/color.h"

class Sequence{
public:
	Sequence();
	virtual ~Sequence();
	virtual void update(float deltaTime);
  void nextElementInVector();
	bool correctSequence(int id);
	int index;
  std::vector<int> order;
private:

};

#endif /* SEQUENCE_H */
