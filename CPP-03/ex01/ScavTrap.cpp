#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap Default Constructor called" << std::endl;
    this->_gardGate = false;
    this->_Name = "default";
    this->_Hp = 100;
    this->_Energy = 50;
    this->_Attack = 20;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Default destructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& _name) :ClapTrap(_name) {
    std::cout << "ScavTrap Constructor for the name called" << std::endl;
    this->_gardGate = false;
    this->_Name = _name;
    this->_Hp = 100;
    this->_Energy = 50;
    this->_Attack = 20;
}

ScavTrap::ScavTrap(const ScavTrap& copy): ClapTrap(copy) {
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
    this->_Name = copy._Name;
    this->_Hp = copy._Hp;
    this->_Energy = copy._Energy;
    this->_Attack = copy._Attack;
    this->_gardGate = copy._gardGate;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& _ScavTrap) {
    std::cout << "ScavTrap assignment operator called" << std::endl;
    if (this == &_ScavTrap)
        return *this;
    this->_Name = _ScavTrap._Name;
    this->_Attack = _ScavTrap._Attack;
    this->_Energy = _ScavTrap._Energy;
    this->_Hp = _ScavTrap._Hp;
    return *this;
}

void ScavTrap::attack(const std::string& target) {
    if (_Energy > 0 && _Attack > 0) {
        std::cout << "ScavTrap " << _Name << " attacks " << target << ", causing "
        << _Attack << " points of damage!" << std::endl;
        _Energy--;
    }
    else if (_Energy == 0) {
        std::cout << "ScavTrap " << _Name << " has insufficient energy" << std::endl;
    }
    else if (_Attack == 0) {
        std::cout << "ScavTrap " << _Name << " has insufficient attack power" << std::endl;
    }
}

void ScavTrap::guardGate() {
    if (!_gardGate) {
        _gardGate = true;    
        std::cout << "ScavTrap " << _Name << " is now in Gate guarding mode" << std::endl;
    }
    else {
        std::cout << "ScavTrap " << _Name << " is already in Gate guarding mode" << std::endl;
    }
}
