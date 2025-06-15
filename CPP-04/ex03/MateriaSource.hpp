#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
    private :
        AMateria* templates[4];

    public :
        MateriaSource();
		MateriaSource(const MateriaSource &copy);
		MateriaSource& operator=(const MateriaSource &src);
		~MateriaSource();
        void learnMateria(AMateria* original);
        AMateria* createMateria(std::string const & type);
};