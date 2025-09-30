#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap();
    FragTrap(const FragTrap &obj);
    FragTrap(const std::string& _name);
    ~FragTrap();

    FragTrap& operator=(const FragTrap& obj);
    void attack(const std::string& target);
    void highFivesGuys(void);

};


