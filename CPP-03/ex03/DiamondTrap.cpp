#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("Default_clap_trap"), FragTrap(), ScavTrap() {
    this->_Name = "Default";
    this->_Hp = FragTrap::_Hp;
    this->_Energy = ScavTrap::_Energy;
    this->_Attack = FragTrap::_Attack;
    std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap Default destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_trap"), FragTrap(), ScavTrap() {
    this->_Name = name;
    this->_Hp = FragTrap::_Hp;
    this->_Energy = ScavTrap::_Energy;
    this->_Attack = FragTrap::_Attack;
    std::cout << "DiamondTrap Default Name Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy) {
	std::cout << "DiamondTrap Copy Constructor called" << std::endl;
	*this = copy;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& _DiamondTrap) {
    if (this == &_DiamondTrap)
        return *this;
    ClapTrap::_Name = _DiamondTrap._Name + "_clap_trap";
    this->_Name = _DiamondTrap._Name;
    this->_Hp = _DiamondTrap._Hp;
    this->_Energy = _DiamondTrap._Energy;
    this->_Attack = _DiamondTrap._Attack;
    return *this;
}

void DiamondTrap::attack(const std::string& name) {
    ScavTrap::attack(name);
}

void DiamondTrap::whoAmI() {
    std::cout << "this DiamondTrap is named " << _Name << ", and the ClapTrap name is " << ClapTrap::_Name << std::endl;
}