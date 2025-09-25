#pragma once 

#include <iostream>

class Weapon
{
    private:
        std::string type;

    public:
        Weapon(const std::string& _type);
        ~Weapon();
        Weapon();

        const std::string& getType(void) const;
        void setType(const std::string &_type);
};

