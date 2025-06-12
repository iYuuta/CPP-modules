#include "FragTrap.hpp"

int main() {
    FragTrap a("steve");
    FragTrap b("yuta");
    FragTrap c("astroid destoyer");

    a.attack("yuta");
    a.highFivesGuys();
    b.takeDamage(10);
    b.beRepaired(10);
    c.attack("steve");
    a.attack("astroid destoyer");
}