#pragma once


#include "ICharacter.hpp"

class Character : public ICharacter
{

public:
    Character();
    Character(const std::string name);
    Character(const Character &obj);
    ~Character();

    Character& operator=(const Character &obj);

    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);

private:
    std::string name;
    AMateria **inventory;
};

