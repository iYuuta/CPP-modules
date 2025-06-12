#include "DiamondTrap.hpp"

int main() {
    DiamondTrap a("steve");
    DiamondTrap b("yuta");
    DiamondTrap c("astroid_destoyer");

    a.attack("yuta");
    a.highFivesGuys();
    b.takeDamage(10);
    b.beRepaired(10);
    c.attack("steve");
    a.attack("astroid_destoyer");
    a.whoAmI();
    b.whoAmI();
    c.whoAmI();
}