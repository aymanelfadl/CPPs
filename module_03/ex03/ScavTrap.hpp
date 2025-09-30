#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(const ScavTrap &obj);
    ScavTrap(const std::string _name);
    ~ScavTrap();
    
    ScavTrap& operator=(const ScavTrap &obj);
    void attack(const std::string& target);
    void guardGate();
};


