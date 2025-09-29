#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
    std::cout << "Useless ScavTrap has been created. [ScavTrap]" << std::endl;
}

ScavTrap::ScavTrap(const std::string _name) : ClapTrap(_name)
{
    std::cout << this->getName() << " has been created. [ScavTrap]" << std::endl;
    this->setMaxHealth(100);
    this->setHealth(100);
    this->setEnergy(50);
    this->setDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
    std::cout << this->getName() << " has been created. [ScavTrap]" << std::endl;
}


ScavTrap& ScavTrap::operator=(const ScavTrap &obj)
{
    if (this == &obj)
        return *this;
    ClapTrap::operator=(obj);
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << this->getName() << " has been removed. [ScavTrap]" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->getEnergy() <= 0)
    {
        std::cout << "ScavTrap " << this->getName() << " is out of energy and cannot attack!" << std::endl;
        return;
    }

    std::ostringstream os;
    os << "ScavTrap " << this->getName();
    os << " attacks " << target;
    os << ", causing " << this->getDamage();
    os << " points of damage!";

    std::cout << os.str() << std::endl;

    this->setEnergy((this->getEnergy() - 1));
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode. [" << this->getName() << "]" << std::endl;
}