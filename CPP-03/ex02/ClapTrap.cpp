#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _Hp(10), _Energy(10), _Attack(0) {
    std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap Default destructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& _name): _Hp(10), _Energy(10), _Attack(0)  {
    std::cout << "ClapTrap Constructor for the name called" << std::endl;
    _Name = _name;
}

ClapTrap::ClapTrap(const ClapTrap& copy) {
    std::cout << "ClapTrap Copy Constructor called" << std::endl;
    this->_Name = copy._Name;
    this->_Attack = copy._Attack;
    this->_Energy = copy._Energy;
    this->_Hp = copy._Hp;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& _ClapTrap) {
    std::cout << "ClapTrap assignment operator called" << std::endl;
    if (this == &_ClapTrap)
        return *this;
    this->_Name = _ClapTrap._Name;
    this->_Attack = _ClapTrap._Attack;
    this->_Energy = _ClapTrap._Energy;
    this->_Hp = _ClapTrap._Hp;
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (_Energy > 0 && _Attack > 0) {
        std::cout << "ClapTrap " << _Name << " attacks " << target << ", causing "
        << _Attack << " points of damage!" << std::endl;
        _Energy--;
    }
    else if (_Energy == 0) {
        std::cout << "ClapTrap " << _Name << " has insufficient energy" << std::endl;
    }
    else if (_Attack == 0) {
        std::cout << "ClapTrap " << _Name << " has insufficient attack power" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_Hp > 0) {
        std::cout << "ClapTrap " << _Name << " received " <<
        amount << " points of damage!" << std::endl;
        if (amount > _Hp)
            _Hp = 0;
        else
            _Hp -= amount;
    }
    else {
        std::cout << "ClapTrap " << _Name << " is already dead" << std::endl;
    }
}
void ClapTrap::beRepaired(unsigned int amount) {
    if (_Energy > 0) {
        std::cout << "ClapTrap " << _Name << " has restored " << amount << " of health points" << std::endl;
        _Hp += amount;
        _Energy--;
    }
    else if (_Energy == 0) {
        std::cout << "ClapTrap " << _Name << " has insufficient energy" << std::endl;
    }
}