#include "Animal.hpp"

Animal::Animal() { std::cout << "Animal has been created" << std::endl; }

Animal::Animal(const Animal &obj) {
    *this = obj;
    std::cout << "Animal has been created" << std::endl;
}

Animal& Animal::operator=(const Animal &obj) {
    if (this == &obj)
        return *this;
    this->type = obj.type;
    return *this;
}

Animal::~Animal() { std::cout << "Animal has been destroyed" << std::endl; }

std::string Animal::getType() const { return this->type; }