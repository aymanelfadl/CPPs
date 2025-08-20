#pragma once 

#include <iostream>
#include <sstream>

class ClapTrap
{
private:
    std::string name;
    int health;
    int energy;
    int attackDamage;

public:
    ClapTrap(const std::string _name);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);


    std::string getName() const;
    int getHealth() const;
    int getEnergy() const;
    int getDamage() const;

    void setName(const std::string& newName);
    void setHealth(int newHealth);
    void setEnergy(int newEnergy);
    void setDamage(int newDamage);
    
};
