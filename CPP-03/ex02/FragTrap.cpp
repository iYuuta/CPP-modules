#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "FragTrap Default Constructor called" << std::endl;\
    this->_Name = "default";
    this->_Hp = 100;
    this->_Energy = 100;
    this->_Attack = 30;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Default destructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& _name) :ClapTrap(_name) {
    std::cout << "FragTrap Constructor for the name called" << std::endl;
    this->_Name = _name;
    this->_Hp = 100;
    this->_Energy = 100;
    this->_Attack = 30;
}

FragTrap::FragTrap(const FragTrap& copy): ClapTrap(copy) {
    std::cout << "FragTrap Copy Constructor called" << std::endl;
    this->_Name = copy._Name;
    this->_Hp = copy._Hp;
    this->_Energy = copy._Energy;
    this->_Attack = copy._Attack;
}

FragTrap& FragTrap::operator=(const FragTrap& _FragTrap) {
    std::cout << "FragTrap assignment operator called" << std::endl;
    if (this == &_FragTrap)
        return *this;
    this->_Name = _FragTrap._Name;
    this->_Attack = _FragTrap._Attack;
    this->_Energy = _FragTrap._Energy;
    this->_Hp = _FragTrap._Hp;
    return *this;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _Name << " wants a highfive" << std::endl;
}