#include "Character.hpp"

Character::Character(): name("default") {
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
    }
}

Character::Character(const std::string& _name): name(_name) {
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        delete inventory[i];
    }
}

Character::Character(const Character& copy) {
    name = copy.name;
    for (int i = 0; i < 4 ; i++) {
        if (!copy.inventory[i])
            inventory[i] = NULL;
        else
            inventory[i] = copy.inventory[i]->clone();
    }
}

Character& Character::operator=(const Character &_character) {
    if (this == &_character)
        return *this;
    name = _character.name;
    for (int i = 0; i < 4 ; i++) {
        delete inventory[i];
        if (!_character.inventory[i])
            inventory[i] = NULL;
        else {    
            inventory[i] = _character.inventory[i]->clone();
        }
    }
    return *this;
}

const std::string& Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (inventory[i] && inventory[i] == m) {
            std::cout << "you have already equiped this AMateria of " << m->getType() << " type" << std::endl;
            break ;
        }
        if (!inventory[i]) {
            inventory[i] = m;
            std::cout << "you have equiped a AMateria of " << m->getType() << " type" << std::endl;
            break ;
        }
        else if (i == 3)
            std::cout << "you have reached the maximum equip load" << std::endl;
    }
}

void Character::unequip(int idx) {
    if (idx < 0 || idx > 3) {
        std::cout << "the index is out of range" << std::endl;
        return ;
    }
    if (inventory[idx])
        std::cout << "you have unequiped a AMateria of " << inventory[idx]->getType() << " type" << std::endl;
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx > 3) {
        std::cout << "the index is out of range" << std::endl;
        return ;
    }
    if (!inventory[idx]) {
        std::cout << "this inventory slot is empty" << std::endl;
        return ;
    }
    inventory[idx]->use(target);
}
