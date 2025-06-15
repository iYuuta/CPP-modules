#pragma once

#include "Animal.hpp"

class Cat : virtual public Animal {
        public :
        Cat();
		Cat(const Cat &copy);
		Cat &operator=(const Cat &Cat);
		~Cat();

        void makeSound();
};