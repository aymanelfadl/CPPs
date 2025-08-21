#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap(const std::string& _name);
    ~FragTrap();

    void attack(const std::string& target);
    void highFivesGuys(void);

};


