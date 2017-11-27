#include "sequence.h"

Sequence::Sequence(std::vector<MyEntity*> b) {
  std::cout << "hello world" << '\n';
  buttons = b;
}
Sequence::~Sequence() {

}
void Sequence::update(float deltaTime) {

}
void Sequence::randomSequence() {
  srand(time(0));
  int r = rand()%(buttons.size());
  MyEntity* b = buttons[r];
  order.push_back(r);
  b->press();
}
