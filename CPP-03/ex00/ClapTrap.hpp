#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
    private :
        std::string     _Name;
        unsigned int    _Hp;
        unsigned int    _Energy;
        unsigned int    _Attack;

    public :
        ClapTrap();
        ClapTrap(const ClapTrap& copy);
        ClapTrap(const std::string& _name);
        ~ClapTrap();
        ClapTrap& operator=(const ClapTrap& _ClapTrap);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

};

#endif