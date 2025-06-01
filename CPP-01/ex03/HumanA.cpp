#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& type) : _Weapon(type), name(name) {}

void HumanA::setWeapon(Weapon Weapon) {
    this->_Weapon = Weapon;
}

void HumanA::attack(void) {
    std::cout << name << " attacks with their " << _Weapon.getType() << std::endl;
}