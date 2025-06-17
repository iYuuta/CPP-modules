#include "AMateria.hpp"

AMateria::AMateria() {};

AMateria::AMateria(const std::string& _type): type(_type) {}

AMateria::AMateria(const AMateria &src) {
    this->type = src.type;
}

AMateria::~AMateria() {}

AMateria& AMateria::operator=(const AMateria &src) {
    if (this == &src)
        return *this;
    this->type = src.type;
}

std::string const & AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter& target) {
    std::cout << "this materia has no use on" << target.getName() <<std::endl;
}
