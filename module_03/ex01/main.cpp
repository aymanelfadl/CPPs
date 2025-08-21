#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap clap("Clappy");
    ScavTrap scav("Scavvy");

    std::cout << "\n--- Battle Start ---\n" << std::endl;

    clap.setDamage(2);
    clap.attack(scav.getName());
    scav.takeDamage(clap.getDamage());

    std::cout << scav.getName() << " health: " << scav.getHealth() << "\n" << std::endl;

    scav.beRepaired(5);
    std::cout << scav.getName() << " health after healing: " << scav.getHealth() << "\n" << std::endl;

    scav.setDamage(8);
    scav.attack(clap.getName());
    clap.takeDamage(scav.getDamage());

    std::cout << clap.getName() << " health: " << clap.getHealth() << "\n" << std::endl;

    scav.guardGate();

    std::cout << "\n--- Battle End ---\n" << std::endl;

    return 0;
}
