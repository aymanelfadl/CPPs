#include "Cat.hpp"

Cat::Cat() : Animal() {
  this->type = "Cat";
  this->brain = new Brain();

  std::cout << "Cat has been created" << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj) {
  *this = obj;
  std::cout << "Cat has been created" << std::endl;
}

Cat& Cat::operator=(const Cat &obj) {
  if (this == &obj)
    return *this;
  this->type = obj.type;
  delete this->brain;
  
  this->brain = new Brain();
  this->brain->setIdeas(obj.brain->getIdeas());

  return *this;
}

Cat::~Cat() { 
  std::cout << "Cat has been destoryed" << std::endl; 
  delete this->brain;
}

void Cat::makeSound() const {
  std::cout << this->type << ": Meow." << std::endl;
}