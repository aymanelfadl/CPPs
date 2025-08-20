#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string _name)
    : name(_name), health(10), energy(10), attackDamage(0)
{
    std::cout << this->name << " has been created." << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << this->name << " has been removed." << std::endl;
}

static std::string getMessage(const ClapTrap& player, const std::string& target, int type)
{
    std::ostringstream os;

    if (type == ATTACK)
    {
        os << "ClapTrap " << player.getName();
        os << " attacks " << target;
        os << ", causing " << player.getDamage();
        os << " points of damage!";
    }
    return os.str();
}

void ClapTrap::attack(const std::string& target)
{
    if (this->energy <= 0)
    {
        std::cout << "ClapTrap " << this->name << " is out of energy and cannot attack!" << std::endl;
        return;
    }
    std::cout << getMessage(*this, target, ATTACK) << std::endl;
    this->setEnergy((this->getEnergy() - 1));

}





std::string ClapTrap::getName() const { return this->name; }
int ClapTrap::getHealth() const { return this->health; }
int ClapTrap::getEnergy() const { return this->energy; }
int ClapTrap::getDamage() const { return this->attackDamage; }

void ClapTrap::setName(const std::string& newName) { this->name = newName; }
void ClapTrap::setHealth(int newHealth) { this->health = newHealth; }
void ClapTrap::setEnergy(int newEnergy) { this->energy = newEnergy; }
void ClapTrap::setDamage(int newDamage) { this->attackDamage = newDamage; }