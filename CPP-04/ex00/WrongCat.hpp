#pragma once

#include "WrongAnimal.hpp"

class WrongCat : virtual public WrongAnimal {
        public :
        WrongCat();
		WrongCat(const WrongCat &copy);
		WrongCat &operator=(const WrongCat &WrongCat);
		~WrongCat();

        void makeSound();
};