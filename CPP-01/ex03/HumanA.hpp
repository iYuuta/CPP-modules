#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA {
    private :
        Weapon& _Weapon;
        std::string name;

    public :
        HumanA(std::string name, Weapon& type);
        void setWeapon(Weapon Weapon);
        void attack();
};

#endif