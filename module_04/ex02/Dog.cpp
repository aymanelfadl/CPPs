#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    this->brain = new Brain();
    
    std::cout << "Dog has been created" << std::endl;
}

Dog::Dog(const Dog& obj)
{
    *this = obj;
    std::cout << "Dog has been created" << std::endl;
}

Dog& Dog::operator=(const Dog& obj)
{
    if (this == &obj)
        return *this;
    this->type = obj.type;

    this->brain = new Brain();
    this->brain->setIdeas(obj.brain->getIdeas());

    return *this;
}

Dog::~Dog() { 
    std::cout << "Dog has been destroyed" << std::endl;
    delete this->brain;
}

void Dog::makeSound() const {
    std::cout << this->type << ": Woof." << std::endl;
}

Brain* Dog::getBrain() const {
    return brain;
}