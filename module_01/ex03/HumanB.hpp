#pragma once

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon *weapon;
    public:
        HumanB(const std::string& _name);
        ~HumanB();
        void setWeapon(Weapon& _weapon);
        void attack();
};