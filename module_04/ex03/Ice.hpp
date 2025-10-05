#pragma once 

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
    Ice(const Ice &obj);
    Ice(const std::string &type);
    Ice& operator=(const Ice &obj);

    ~Ice();
    
    void use(ICharacter &target);
    AMateria *clone() const;

};