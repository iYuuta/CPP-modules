#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {}

Ice::Ice(const Ice &src) {
	type = src.type;
}

Ice::~Ice() {}

Ice& Ice::operator=(const Ice &src) {
	if (this != &src)
		type = src.type;
	return (*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const {
    return new Ice;
}

