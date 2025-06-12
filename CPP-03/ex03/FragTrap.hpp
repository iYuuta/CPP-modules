#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
    public :
        FragTrap();
        ~FragTrap();
        FragTrap(const std::string& _name);
        FragTrap(const FragTrap& copy);
        FragTrap& operator=(const FragTrap& _FragTrap);
        void highFivesGuys(void);
};
