#include "Character.hpp"


Character::Character() {
    std::cout << "Default Character has been created." << std::endl;
    this->inventory = new AMateria*[4];
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::Character(const std::string name) {
    this->name = name;
    this->inventory = new AMateria*[4];
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
    
    std::cout << "The " << this->name << " character has been created." << std::endl;
}

Character::Character(const Character &obj) {
    *this = obj;
    std::cout << "The " << this->name << " character has been created." << std::endl;
}

Character& Character::operator=(const Character &obj) {
    if (this == &obj)
        return *this;

    this->name = obj.name;
    this->inventory = new AMateria*[4];
    for (int i = 0; i < 4; i++)
        this->inventory[i] = obj.inventory[i];
    return *this;   
}

Character::~Character() {
    std::cout << "this " << this->name << " has been destroyed" << std::endl;
    
    for (int i = 0; i < 4; i++)
        delete this->inventory[i];
    
    delete[] this->inventory;
}

std::string const &Character::getName() const { return this->name; }

void Character::equip(AMateria *m) {
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i] == m)
            return ;
        if (this->inventory[i] == NULL)
        {
            this->inventory[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx) {
    if (idx > -1 && idx < 4)
        this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
    if (idx > -1 && idx < 4)
        if (this->inventory[idx] != NULL)
            this->inventory[idx]->use(target);
}