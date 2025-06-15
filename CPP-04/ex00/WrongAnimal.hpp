#pragma once

#include <string>
#include <iostream>

class WrongAnimal {
    protected :
        std::string type;
    public :
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal &operator=(const WrongAnimal &WrongAnimal);
		virtual ~WrongAnimal();

		virtual void makeSound();
		std::string& getType(void) ;
};