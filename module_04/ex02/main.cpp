#include "Cat.hpp"
#include "Dog.hpp"


void pirtf(Animal *ani)
{
    std::cout << ani->getType() << std::endl;
    ani->makeSound();
    delete ani;
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        if (i < 2)
            pirtf(new Dog());
        else 
            pirtf(new Cat());
    }
    
}
