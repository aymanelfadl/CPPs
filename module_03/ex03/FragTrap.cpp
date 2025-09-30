#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "Useless FragTrap has been created. [FragTrap]" << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj)
{
    std::cout << this->getName() << " has been created. [FragTrap]" << std::endl;
}

FragTrap::FragTrap(const std::string &_name) : ClapTrap(_name)
{
    std::cout << this->getName() << " has been created. [FragTrap]" << std::endl;
    this->setMaxHealth(100);
    this->setHealth(100);
    this->setEnergy(100);
    this->setDamage(20);
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
    if (this == &obj)
        return *this;
    ClapTrap::operator=(obj);    
    return *this;   
}

void FragTrap::attack(const std::string &target)
{
    if (this->getEnergy() <= 0)
    {
        std::cout << "FragTrap " << this->getName() << " is out of energy and cannot attack!" << std::endl;
        return;
    }

    std::ostringstream os;
    os << "FragTrap " << this->getName();
    os << " attacks " << target;
    os << ", causing " << this->getDamage();
    os << " points of damage!";

    std::cout << os.str() << std::endl;

    this->setEnergy((this->getEnergy() - 1));
}

FragTrap::~FragTrap()
{
    std::cout << this->getName() << " has been removed. [FragTrap]" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->getName() << " is requesting a high five!" << std::endl;
}