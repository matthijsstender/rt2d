#include "sequence.h"

Sequence::Sequence() {
  index = 0;
}
Sequence::~Sequence() {

}
void Sequence::update(float deltaTime) {

}

bool Sequence::correctSequence(int id) {
  std::cout << "index: " << index << '\n';
  std::cout << "order[index]: " << order[index] << '\n';
  std::cout << "bt->id: " << id << '\n';
	if (order[index] == id) {
    index++;
		return true;
	}
  index = 0;
  order.clear();
	return false;
}
void Sequence::nextElementInVector() {
  srand(time(0));
  int r = rand()%(4);
  order.push_back(r);
}
