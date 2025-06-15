#pragma once

#include "Ice.hpp"
#include "Cure.hpp"

class Character : public ICharacter {
    private :
        std::string name;
        AMateria* inventory[4];
    
    public :
        Character();
        Character(const std::string& _name);
        Character(const Character& copy);
        Character& operator=(const Character &_character);
        ~Character();
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};