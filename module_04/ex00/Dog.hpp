#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
    private:
    int *x;
public:
    Dog();
    Dog(const Dog& obj);
    Dog& operator=(const Dog& obj);
    ~Dog();

    void makeSound() const;
};
