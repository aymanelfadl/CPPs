#include "Zombie.hpp"

int main()
{
    randomChump("joe");

    Zombie *z_ptr = newZombie("ayman");
    z_ptr->announce();
    
    delete z_ptr;
}