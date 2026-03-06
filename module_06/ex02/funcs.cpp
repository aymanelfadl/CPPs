#include "Base.h"
#include "A.h"
#include "B.h"
#include "C.h"

Base *createA() { return new A; }
Base *createB() { return new B; }
Base *createC() { return new C; }

Base *generate()
{


    std::srand(std::time(NULL));
    int i = std::rand() % 3;

    Base *(*creators[3])() = {createA, createB, createC};

    return creators[i]();
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "This is A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "This is B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "This is C\n";
    else
        std::cout << "Unknown type\n";
}

void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "This is A\n";
        return;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "This is B\n";
        return;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "This is C\n";
        return;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Unknown type\n";
}