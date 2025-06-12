#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
    private :
        bool _gardGate;

    public :
        ScavTrap();
        ~ScavTrap();
        ScavTrap(const std::string& _name);
        ScavTrap(const ScavTrap& copy);
        ScavTrap& operator=(const ScavTrap& _ScavTrap);
        void guardGate();
        void attack(const std::string& target);

};
