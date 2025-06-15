#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : virtual public Animal {
    private :
        Brain* _Brain;
    public :
        Cat();
		Cat(const Cat &copy);
		Cat &operator=(const Cat &Cat);
		~Cat();
        void makeSound();
};