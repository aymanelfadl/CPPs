#include "AMateria.hpp"

AMateria::AMateria() { std::cout << "AMateria has been created." << std::endl; }

AMateria::AMateria(const AMateria &obj) {
    std::cout << "AMateria has been created." << std::endl;
    *this = obj;
}

AMateria::AMateria(std::string const &type) {
    this->type = type;
    std::cout << "AMateria has been created." << std::endl;
}

AMateria& AMateria::operator=(const AMateria &obj) {
    if (this == &obj)
        return *this;
    this->type = obj.type;
    return *this;
}

std::string const& AMateria::getType() const { return this->type; }

void AMateria::use(ICharacter &target) { 
    std::cout << "Abstract Materia spells in use on" << target.getName() << std::endl;
}