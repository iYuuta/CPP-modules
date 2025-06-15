#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        templates[i] = NULL;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++)
        delete templates[i];
}

MateriaSource::MateriaSource(const MateriaSource &copy) {
    for (int i = 0; i < 4; i++) {
        if (copy.templates[i])
            templates[i] = copy.templates[i]->clone();
        else
            templates[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource &src) {
    for (int i = 0; i < 4; i++) {
        delete templates[i];
        if (src.templates[i])
            templates[i] = src.templates[i]->clone();
        else
            templates[i] = NULL;
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* original) {
    for (int i = 0; i < 4; i++) {
        if (!templates[i]) {
            templates[i] = original->clone();
            return ;
        }
    }
    std::cout << "you have reached the maximum number of AMateria templates" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 3; i >= 0; i--) {
        if (templates[i] && templates[i]->getType() == type)
            return templates[i]->clone();
    }
    std::cout << "cannot identify the given AMateria" << std::endl;
    return 0;
}
