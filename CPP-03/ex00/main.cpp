#include "ClapTrap.hpp"

int main() {
    ClapTrap a("steve");
    ClapTrap b("yuta");
    ClapTrap c("astroid destroyer");

    a.attack("yuta");
    b.takeDamage(10);
    b.beRepaired(10);
    c.attack("steve");
    a.attack("astroid destroyer");
}