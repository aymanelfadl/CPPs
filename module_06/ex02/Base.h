#pragma once

class Base
{
    public:
        virtual ~Base();

};

#include <iostream>
#include <ctime>
#include <cstdlib>

Base * generate(void);
void identify(Base* p);
void identify(Base& p);
