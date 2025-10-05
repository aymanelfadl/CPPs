#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria **inventory;
public:
    MateriaSource();
    MateriaSource(const MateriaSource &obj);
    MateriaSource& operator=(const MateriaSource &obj);
    ~MateriaSource();

    void learnMateria(AMateria *obj);
    AMateria *createMateria(std::string const &type);
};

