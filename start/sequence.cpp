#include "sequence.h"

Sequence::Sequence() {
  index = 0;
  srand(time(0));
}
Sequence::~Sequence() {

}
void Sequence::update(float deltaTime) {

}

bool Sequence::correctSequence(int id) {
  std::cout << "index: " << index << '\n';
  //std::cout << "order[index]: " << order[index] << '\n';
  //std::cout << "bt->id: " << id << '\n';
	if (order[index] == id) {
    std::cout << "right" << '\n';
    index++;
		return true;
	}
  std::cout << "wrong retry" << '\n';
  index = 0;
	return false;
}

bool Sequence::isDone(){
  if(this->getElementAtIndex(index) == -1){
    index = 0;
    return true;
  }
  return false;
}

int Sequence::getElementAtIndex(int _index) {
  if (_index >= order.size()) {
    return -1;
  } else {
    return order[_index];
  }
}
void Sequence::nextElementInVector() {
  int r = rand()%(4);
  order.push_back(r);
  std::cout << "random sequence: "  << r << '\n';
}
