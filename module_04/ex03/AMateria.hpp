#pragma once 

#include <iostream>
#include <ICharacter.hpp>

class AMateria
{
public:
    AMateria();
    AMateria(std::string const &type);
    AMateria(const AMateria &obj);

    AMateria& operator=(const AMateria &obj);
    
    std::string const &getType() const;
    
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);

protected:
    std::string type;    
};