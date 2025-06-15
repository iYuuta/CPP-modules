#pragma once

#include "Animal.hpp"

class Dog : virtual public Animal {
        public :
        Dog();
		Dog(const Dog& copy);
		Dog &operator=(const Dog& _Dog);
		~Dog();

        void makeSound();
};