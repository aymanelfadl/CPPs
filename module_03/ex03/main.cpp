#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap clap("Clappy");
    ScavTrap scav("Scavvy");
    FragTrap frag("Fraggy");

    std::cout << "\n--- Battle Start ---\n"
              << std::endl;

    clap.setDamage(2);
    clap.attack(scav.getName());
    scav.takeDamage(clap.getDamage());

    std::cout << scav.getName() << " health: " << scav.getHealth() << std::endl;

    scav.beRepaired(5);
    std::cout << scav.getName() << " health after healing: " << scav.getHealth() << std::endl;

    scav.setDamage(8);
    scav.attack(clap.getName());
    clap.takeDamage(scav.getDamage());

    std::cout << clap.getName() << " health: " << clap.getHealth() << std::endl;


    scav.guardGate();

    std::cout << "\n--- FragTrap Action ---\n" << std::endl;

    frag.setDamage(10);
    frag.attack(clap.getName());
    clap.takeDamage(frag.getDamage());
    std::cout << clap.getName() << " health after FragTrap attack: " << clap.getHealth() << std::endl;

    frag.highFivesGuys();

    std::cout << "\n--- Battle End ---\n" << std::endl;

    return 0;
}
