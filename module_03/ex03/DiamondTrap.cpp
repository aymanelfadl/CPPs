#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& _name) : ClapTrap(_name), FragTrap(_name), ScavTrap(_name), name(_name) 
{
    std::cout << _name << std::endl;
    std::cout << this->name << " has been created. [DiamondTrap]" << std::endl;

    this->setHealth(FragTrap::getHealth());
    this->setMaxHealth(FragTrap::getMaxHealth());
    this->setEnergy(ScavTrap::getEnergy());
    this->setDamage(FragTrap::getDamage());
}

DiamondTrap::~DiamondTrap()
{
    std::cout << this->getName() << " has been removed. [DiamondTrap]" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "DiamondTrap name: " << this->name << ", ClapTrap name: " << ClapTrap::getName() << std::endl;
}
