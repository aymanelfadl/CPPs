#pragma once

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
    std::string name;
    Weapon &weapon;
public:
    HumanA(const std::string& _name, Weapon& _weapon);
    ~HumanA();

    void attack();
};