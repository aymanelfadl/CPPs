#pragma once 

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap 
{
private:
    std::string name;
public:
    DiamondTrap(const std::string& _name);
    ~DiamondTrap();

    void attack(const std::string& target);
    void whoAmI();
};


