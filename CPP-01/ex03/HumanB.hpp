#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB {
    private :
        Weapon* _Weapon;
        std::string name;

    public :
        HumanB(std::string name);
        void attack();
        void setWeapon(Weapon &weapon);
};

#endif