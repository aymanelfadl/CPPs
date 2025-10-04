#include "WrongCat.hpp"

WrongCat::WrongCat() {
  this->type = "WrongCat";
  std::cout << "WrongCat has been created" << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj) {
  *this = obj;
  std::cout << "WrongCat has been created" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &obj) {
  if (this == &obj)
    return *this;
  this->type = obj.type;
  return *this;
}

WrongCat::~WrongCat() { std::cout << "WrongCat has been destoryed" << std::endl; }

void WrongCat::makeSound() const {
  std::cout << this->type << ": Meow." << std::endl;
}