#include "Zombie.hpp"

int main()
{
    int size = 3;
    Zombie* z_ptr = zombieHorde(3, "ayman");
    for (int i = 0; i < size; i++)
    {
        z_ptr[i].announce();
    }
    delete[] z_ptr;
}