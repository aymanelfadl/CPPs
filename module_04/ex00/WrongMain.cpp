#include "WrongCat.hpp"


int main()
{
    WrongAnimal *i = new WrongCat();

    std::cout << i->getType() << std::endl;
    i->makeSound();

    delete i;
} 