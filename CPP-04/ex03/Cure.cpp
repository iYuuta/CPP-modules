#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {}

Cure::Cure(const Cure &src) {
	type = src.type;
}

Cure& Cure::operator=(const Cure &src) {
	if (this != &src)
		type = src.type;
	return (*this);
}

Cure::~Cure() {}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

AMateria* Cure::clone() const {
    return new Cure;
}
