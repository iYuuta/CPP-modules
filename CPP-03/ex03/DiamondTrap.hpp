#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
    private :
        std::string _Name;

    public :
        DiamondTrap();
        DiamondTrap(const std::string& name);
        DiamondTrap(const DiamondTrap& copy);
        ~DiamondTrap();
        DiamondTrap& operator=(const DiamondTrap& _DiamondTrap);
        void attack(const std::string& name);
        void whoAmI();
};
