#include "Animal.hpp"
#include <iostream>

Animal::Animal() { std::cout << "Animal has been created" << std::endl; }

Animal::Animal(const Animal &obj) {
  *this = obj;
  std::cout << "Animal has been created" << std::endl;
}

Animal &Animal::operator=(const Animal &obj) {
  if (this == &obj)
    return *this;

  this->type = obj.type;
  return *this;
}

Animal::~Animal() { std::cout << "Animal has been destoryed" << std::endl; }

void Animal::makeSound() {
  std::cout << "This animal has no specific sound." << std::endl;
}
