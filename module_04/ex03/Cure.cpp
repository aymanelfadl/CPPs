#include "Cure.hpp"


Cure::Cure() : AMateria() {
    std::cout << "Cure has been created." << std::endl;
    this->type = "cure"; 
}

Cure::Cure(const Cure &obj) : AMateria(obj){
    std::cout << "Cure has bewn created." << std::endl; 
    *this = obj;
}

Cure::Cure(const std::string &type) : AMateria(type) {
    std::cout << "Cure has bewn created." << std::endl;
}

Cure& Cure::operator=(const Cure &obj) {
    if (this == &obj)
        return *this;
    this->type = obj.type;
    return *this;
}

Cure::~Cure() {
    std::cout << "Cure has been destroyed." << std::endl;
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName()<< "'s wounds *" << std::endl;
}


AMateria* Cure::clone() const { return new Cure(); }