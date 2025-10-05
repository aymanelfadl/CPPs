#include "Ice.hpp"

Ice::Ice() : AMateria() {
    std::cout << "Ice has been created." << std::endl;
    this->type = "ice";
}

Ice::Ice(const std::string &type) : AMateria(type) {
    std::cout << "Ice has been created." << std::endl;
    this->type = type;
}

Ice::Ice(const Ice &obj) {
    std::cout << "Ice has been created." << std::endl;
    *this = obj;
}


Ice& Ice::operator=(const Ice& obj) {
    if (this == &obj)
        return *this;
    this->type = obj.type;
    return *this;
}


Ice::~Ice() { std::cout << "Ice has been destroyed." << std::endl; }

void Ice::use(ICharacter &target) { std::cout << "* shoots an ice bolt at " << target.getName()<< " *" << std::endl; }

AMateria* Ice::clone() const { return new Ice(); }
