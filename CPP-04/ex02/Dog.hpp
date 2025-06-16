#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    private :
        Brain* _Brain;
    public :
        Dog();
		Dog(const Dog& copy);
		Dog &operator=(const Dog& _Dog);
		~Dog();
        void makeSound();
};