#include "Zombie.hpp"

Zombie* newZombie( std::string name ) {
    Zombie* new_zombie = new(std::nothrow) Zombie(name);

    return (new_zombie);
}