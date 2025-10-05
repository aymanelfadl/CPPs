#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
    // {
    //     IMateriaSource *src = new MateriaSource();

    //     Ice *ice = new Ice();
    //     Cure *cure = new Cure();

    //     src->learnMateria(ice);
    //     src->learnMateria(cure);

    //     ICharacter *me = new Character("me");
    //     AMateria *tmp;
    //     tmp = src->createMateria("ice");
    //     me->equip(tmp);
    //     tmp = src->createMateria("cure");
    //     me->equip(tmp);

    //     ICharacter *bob = new Character("bob");
    //     me->use(0, *bob);
    //     me->use(1, *bob);

    //     delete bob;
    //     delete me;
    //     delete src;
    // }

    {
        // IMateriaSource *src = new MateriaSource();

        // Ice *ice1 = new Ice();
        // Cure *cure1 = new Cure();

        // Ice *ice2 = new Ice();
        // Cure *cure2 = new Cure();
        // Cure *cure3 = new Cure();

        // src->learnMateria(ice1);
        // src->learnMateria(ice2);
        // src->learnMateria(cure1);
        // src->learnMateria(cure2);

        // src->learnMateria(cure3);

        // ICharacter *me = new Character("ayman");
        // AMateria *tmp;

        // tmp = src->createMateria("ice");
        // me->equip(tmp);
        // tmp = src->createMateria("ice");
        // me->equip(tmp);
        // tmp = src->createMateria("cure");
        // me->equip(tmp);
        // tmp = src->createMateria("cure");
        // me->equip(tmp);
        // tmp = src->createMateria("cure");
        // me->unequip(0);
        // me->equip(tmp);

        // ICharacter *bob = new Character("bob");
        // me->use(0, *bob);
        // me->use(1, *bob);
        // me->use(2, *bob);
        // me->use(3, *bob);

        // // delete ice1;
        // delete src;
        // delete bob;
        // delete me;
    }

    {
        IMateriaSource *src = new MateriaSource();

        Ice *ice = new Ice();
        Cure *cure = new Cure();

        src->learnMateria(ice);
        src->learnMateria(cure);

        ICharacter *me = new Character("me");
        AMateria *tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        me->equip(tmp);

        ICharacter *bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);

        delete src;
        delete bob;
        delete me;
    }
    return 0;
}