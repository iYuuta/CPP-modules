#include "ScavTrap.hpp"

int main() {
    ScavTrap a("steve");
    ScavTrap b("yuta");
    ScavTrap c("astroid destoyer");

    a.attack("yuta");
    a.guardGate();
    b.takeDamage(10);
    b.beRepaired(10);
    c.attack("steve");
    a.attack("astroid destoyer");
}