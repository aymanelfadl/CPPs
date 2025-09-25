#include "HumanB.hpp"

HumanB::HumanB(const std::string &_name) : name(_name), weapon(NULL)
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
    if (!this->weapon)
    {
        std::cout << name << " attacks bare-handed!" << std::endl;
        return ;
    }
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}