#include "HumanB.hpp"

HumanB::HumanB(const std::string &_name) : name(_name)
{
}

HumanB::~HumanB()
{
}
void HumanB::setWeapon(Weapon &_weapon)
{
    weapon = &_weapon;
}

void HumanB::attack()
{
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}