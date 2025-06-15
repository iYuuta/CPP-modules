#pragma once

#include <string>
#include <iostream>

class Animal {
    protected :
        std::string type;
    public :
		Animal();
		Animal(const Animal &copy);
		Animal &operator=(const Animal &Animal);
		virtual ~Animal();

		virtual void makeSound() = 0;
		std::string& getType(void) ;
};