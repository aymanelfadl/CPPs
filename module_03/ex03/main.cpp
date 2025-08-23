#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    // ClapTrap clap("Clappy");
    // ScavTrap scav("Scavvy");
    // FragTrap frag("Fraggy");
    DiamondTrap diamond("D1");

    // std::cout << "\n--- Battle Start ---\n\n";

    // clap.setDamage(2);
    // clap.attack(scav.getName());
    // scav.takeDamage(clap.getDamage());
    // std::cout << scav.getName() << " health: " << scav.getHealth() << "\n\n";

    // scav.beRepaired(5);
    // std::cout << scav.getName() << " health after healing: " << scav.getHealth() << "\n\n";

    // scav.setDamage(8);
    // scav.attack(clap.getName());
    // clap.takeDamage(scav.getDamage());
    // std::cout << clap.getName() << " health: " << clap.getHealth() << "\n\n";

    // scav.guardGate();

    // std::cout << "--- FragTrap Action ---\n\n";

    // frag.setDamage(10);
    // frag.attack(clap.getName());
    // clap.takeDamage(frag.getDamage());
    // std::cout << clap.getName() << " health after FragTrap attack: " << clap.getHealth() << "\n\n";

    // frag.highFivesGuys();

    // std::cout << "--- DiamondTrap Action ---\n\n";

    // diamond.attack(scav.getName());
    // scav.takeDamage(diamond.getDamage());
    // diamond.beRepaired(5);

    // diamond.whoAmI(); // shows both DiamondTrap name and ClapTrap base name

    // std::cout << "\n--- Battle End ---\n" << std::endl;

    return 0;
}
