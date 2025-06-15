#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main() {
    IMateriaSource* src = new MateriaSource();
    AMateria* to_clean = new Ice();
    src->learnMateria(to_clean);
    delete to_clean;
    to_clean = new Cure();
    src->learnMateria(to_clean);
    delete to_clean;

    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    to_clean = tmp;
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    me->unequip(0);
    me->use(0, *bob);
    delete bob;
    delete me;
    delete src;
    delete to_clean;
    return 0;
}
