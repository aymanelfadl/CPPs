#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>
#include <string>
#include <sstream>

void printTestHeader(const std::string &testName)
{
    std::cout << "\n"
              << std::string(50, '=') << std::endl;
    std::cout << "TEST: " << testName << std::endl;
    std::cout << std::string(50, '=') << std::endl;
}

int main()
{
    {
        printTestHeader("Basic Exercise Test (from subject)");

        IMateriaSource *src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter *me = new Character("me");
        AMateria *tmp;

        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);

        ICharacter *bob = new Character("bob");

        me->use(0, *bob);
        me->use(1, *bob);

        delete bob;
        delete me;
        delete src;
    }

    {
        printTestHeader("Character Deep Copy Test");

  
        Character original("Original");
        original.equip(new Ice());
        original.equip(new Cure());

 
        Character copy(original);
        
        Character copy2;

        Character target("Target");

        std::cout << "Original character actions:" << std::endl;
        original.use(0, target);
        original.use(1, target);

        std::cout << "\nCopied character actions:" << std::endl;
        copy.use(0, target);
        copy.use(1, target);

        std::cout << "\nCopied2 character actions:" << std::endl;
        copy2 = original;
        copy2.use(0, target);
        copy2.use(1, target);

    }

    {
        printTestHeader("Polymorphism Test");

        AMateria *materias[4];
        materias[0] = new Ice();
        materias[1] = new Cure();
        materias[2] = new Ice();
        materias[3] = new Cure();

        Character polymorphTest("PolyTest");
        Character target("Target");

        std::cout << "Testing polymorphic behavior:" << std::endl;
        for (int i = 0; i < 4; i++)
        {
            std::cout << "Type: " << materias[i]->getType() << " - ";
            materias[i]->use(target);
        }
        for (int i = 0; i < 4; i++)
        {
            delete materias[i];
        }
    }

    std::cout << std::endl;


    return 0;
}