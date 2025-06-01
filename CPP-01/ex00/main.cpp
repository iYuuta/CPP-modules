#include "Zombie.hpp"

int main()
{
    Zombie *new_zombie;

    randomChump("fred");
    new_zombie = newZombie("creg");
    if (!new_zombie)
        return 1;
    new_zombie->announce();
    delete new_zombie;
}