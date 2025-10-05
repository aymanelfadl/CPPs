#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    std::cout << "MateriaSource has been created." << std::endl;
    this->inventory = new AMateria*[4];
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &obj) {
    this->inventory = new AMateria*[4];
    *this = obj;
    std::cout << "MateriaSource has been created." << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &obj)
{
    if (this == &obj)
        return *this;

    for (int i = 0; i < 4; i++)
        delete this->inventory[i];
    delete[] this->inventory;

    this->inventory = new AMateria*[4];
    for (int i = 0; i < 4; i++) {
        if (obj.inventory[i])
            this->inventory[i] = obj.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }

    return *this;    
}

MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource has been destroyed." << std::endl;
    for (int i = 0; i < 4; ++i)
        delete this->inventory[i];
    delete[] this->inventory;
}

void MateriaSource::learnMateria(AMateria *obj) {
    if (!obj)
        return ;
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i] == NULL) {
            this->inventory[i] = obj->clone();
            delete obj;
            return ;
        }
    }
    delete obj;
}

AMateria* MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i]->getType() == type)
            return this->inventory[i]->clone();
    }
    return 0;
}