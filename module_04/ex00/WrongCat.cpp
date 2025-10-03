#include "Cat.hpp"

Cat::Cat() {
  this->type = "Cat";
  std::cout << "Cat has been created" << std::endl;
}

Cat::Cat(const Cat &obj) {
  *this = obj;
  std::cout << "Cat has been created" << std::endl;
}

Cat& Cat::operator=(const Cat &obj) {
  if (this == &obj)
    return *this;
  this->type = obj.type;
  return *this;
}

Cat::~Cat() { std::cout << "Cat has been destoryed" << std::endl; }

void Cat::makeSound() const {
  std::cout << this->type << ": Meow." << std::endl;
}