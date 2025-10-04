#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal* Zoo[10];

    for (int i = 0; i < 10; i++)
    {
        if (i < 5)
            Zoo[i] = new Dog();
        else
            Zoo[i] = new Cat();
    }

    for (int i = 0; i < 10; ++i)
    {
        Zoo[i]->makeSound();
        delete Zoo[i];
    }

    // {
        // std::string arr[100] = {};
        // arr[0] = "hey";
        // arr[1] = "hola";
        // arr[2] = "hahah";

        // std::cout << "--- Create Dog a ---" << std::endl;
        // Dog a;

        // a.getBrain()->setIdeas(arr);
        // for (int i = 0; i < 3; i++)
        //     std::cout << a.getBrain()->getIdeas()[i] << std::endl;

        // std::cout << "--- Copy Dog b from a ---" << std::endl;
        // Dog b(a);
        // for (int i = 0; i < 3; i++)
        //     std::cout << a.getBrain()->getIdeas()[i] << std::endl;

        // std::cout << "--- Addresses of brains ---" << std::endl;
        // std::cout << "a brain: " << a.getBrain() << std::endl;
        // std::cout << "b brain: " << b.getBrain() << std::endl;       
    // }
}
