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

		void makeSound() const;
		std::string& getType(void) ;
};