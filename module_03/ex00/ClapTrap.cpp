#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string _name)
    : name(_name), health(10), maxHealth(10), energy(10), attackDamage(0)
{
    std::cout << this->name << " has been created. [ClapTrap]" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << this->name << " has been removed. [ClapTrap]" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->energy <= 0)
    {
        std::cout << "ClapTrap " << this->name << " is out of energy and cannot attack!" << std::endl;
        return;
    }
    
    std::ostringstream os;
    os << "ClapTrap " << this->getName();
    os << " attacks " << target;
    os << ", causing " << this->getDamage();
    os << " points of damage!";

    std::cout << os.str() << std::endl;

    this->setEnergy((this->getEnergy() - 1));
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energy <= 0)
    {
        std::cout << "ClapTrap " << this->name << " is out of energy and cannot repairs itself!" << std::endl;
        return;
    }

    std::ostringstream os;
    os << "ClapTrap " << this->getName();
    os << " heals for " << amount;
    os << " hit points!";

    std::cout << os.str() << std::endl;

    int neededHealth = this->getMaxHealth() - this->getHealth();
    if ((int)amount <= neededHealth)
        this->setHealth(this->getHealth() + amount);
    else
        this->setHealth(this->getMaxHealth());

    this->setEnergy((this->getEnergy() - 1));
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::ostringstream os;
    os << "ClapTrap " << this->getName();
    os << " takes " << amount;
    os << " points of damage!";

    std::cout << os.str() << std::endl;
    int damageTaken = this->getHealth() - amount;
    if (damageTaken >= 0)
        this->setHealth(damageTaken);
    else
        this->setHealth(0);
}


std::string ClapTrap::getName() const { return this->name; }
int ClapTrap::getHealth() const { return this->health; }
int ClapTrap::getEnergy() const { return this->energy; }
int ClapTrap::getDamage() const { return this->attackDamage; }
int ClapTrap::getMaxHealth() const { return this->maxHealth; }

void ClapTrap::setName(const std::string& newName) { this->name = newName; }
void ClapTrap::setHealth(int newHealth) { this->health = newHealth; }
void ClapTrap::setEnergy(int newEnergy) { this->energy = newEnergy; }
void ClapTrap::setDamage(int newDamage) { this->attackDamage = newDamage; }
void ClapTrap::setMaxHealth(int max) { this->maxHealth = max; }
