#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) {
    this->type = type;
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter& target) {
    std::cout << "this materia has no use on" << target.getName() <<std::endl;
}
