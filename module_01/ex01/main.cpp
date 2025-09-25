#include "Zombie.hpp"

int main()
{
    int size = 3;
    Zombie* z_ptr = zombieHorde(3, "ayman");
    if (!z_ptr)
        return 1;
    for (int i = 0; i < size; i++)
    {
        z_ptr[i].announce();
    }
    delete[] z_ptr;
}