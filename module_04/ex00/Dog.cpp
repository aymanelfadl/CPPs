#include "Dog.hpp"

Dog::Dog()
{
    this->x = new int[10];
    this->type = "Dog";
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
    return *this;
}

Dog::~Dog() { delete this->x; std::cout << "Animal has been destroyed" << std::endl; }

void Dog::makeSound() const {
    std::cout << this->type << ": Woof." << std::endl;
}