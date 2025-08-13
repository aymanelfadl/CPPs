#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(const std::string& _type)
{
    setType(_type);
}
Weapon::~Weapon()
{

}

std::string Weapon::getType(void) const
{
    return type;
}

void Weapon::setType(const std::string &_type)
{
    type = _type;
}