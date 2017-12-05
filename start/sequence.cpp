#include "sequence.h"

Sequence::Sequence(std::vector<Button*> b) {
  std::cout << "hello world" << '\n';
  buttons = b;
  index = 0;
}
Sequence::~Sequence() {

}
void Sequence::update(float deltaTime) {

}

bool Sequence::correctSequence(Button* bt) {
  std::cout << "index: " << index << '\n';
  std::cout << "oder[index]: " << order[index] << '\n';
  std::cout << "bt->id: " << bt->id << '\n';
	if (order[index] == bt->id) {
    index++;
		return true;
	}
  index = 0;
	return false;
}

void Sequence::randomSequence() {
  srand(time(0));
  int r = rand()%(buttons.size());
  b = buttons[r];
  order.push_back(r);
  b->press();
}
