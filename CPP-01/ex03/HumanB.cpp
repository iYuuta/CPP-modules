#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
    this->name = name;
    this->_Weapon = NULL;
}

void HumanB::setWeapon(Weapon &Weapon) {
    this->_Weapon = &Weapon;
}

void HumanB::attack(void) {
    if(!this->_Weapon)
        return ;
    std::cout << name << " attacks with their " << _Weapon->getType() << std::endl;
}