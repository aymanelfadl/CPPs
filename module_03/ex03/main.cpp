#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap diamond("D1");

    std::cout << "\n-- Testing attack --\n";
    diamond.attack("Enemy1");

    std::cout << "\n-- Testing whoAmI --\n";
    diamond.whoAmI();

    std::cout << "\n-- Testing repair --\n";
    diamond.beRepaired(200);

    return 0;
}
