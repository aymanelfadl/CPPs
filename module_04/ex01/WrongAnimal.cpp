#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() { std::cout << "WrongAnimal has been created" << std::endl; }

WrongAnimal::WrongAnimal(const WrongAnimal &obj) {
  *this = obj;
  std::cout << "WrongAnimal has been created" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &obj) {
  if (this == &obj)
    return *this;

  this->type = obj.type;
  return *this;
}

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal has been destroyed" << std::endl; }

std::string WrongAnimal::getType() const { return this->type; }

void WrongAnimal::makeSound() const {
  std::cout << "This Wronganimal has no specific sound." << std::endl;
}
