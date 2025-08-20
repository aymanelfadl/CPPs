#include "ClapTrap.hpp"

int main()
{
    ClapTrap bot1("Alpha");
    ClapTrap bot2("Bravo");

    std::cout << "\n--- Battle Start ---\n" << std::endl;

    bot1.setDamage(3); 
    bot1.attack(bot2.getName());
    bot2.takeDamage(bot1.getDamage());

    std::cout << "\n" << bot2.getName() << " health: " << bot2.getHealth() << std::endl;

    bot2.beRepaired(5);
    std::cout << bot2.getName() << " health after healing: " << bot2.getHealth() << std::endl;

    bot2.attack(bot1.getName());
    bot1.takeDamage(bot2.getDamage());

    std::cout << "\n--- Battle End ---\n" << std::endl;

    return 0;
}
