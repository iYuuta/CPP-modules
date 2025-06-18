#pragma once

#include "Animal.hpp"

class Dog : public Animal {
        public :
        Dog();
		Dog(const Dog& copy);
		Dog &operator=(const Dog& _Dog);
		virtual ~Dog();

        void makeSound() const;
};