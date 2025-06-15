#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	std::cout << std::endl << "/****************** animal tests ************************/" << std::endl;
	std::cout << "// ANIMAL CONSTRUCTORS" << std::endl;
	Animal	a1;
	std::cout << "this animal type is " << a1.getType() << std::endl;
	std::cout << "// ANIMAL MAKESOUND" << std::endl;
	a1.makeSound();
	std::cout << std::endl << "/****************** Cat tests ************************/" << std::endl;
	std::cout << "// CAT CONSTRUCTORS" << std::endl;
	Animal		*_Cat = new Cat;
	std::cout << "this animal type is " << _Cat->getType() << std::endl;
	std::cout << "// CAT MAKESOUND" << std::endl;
	_Cat->makeSound();
	std::cout << std::endl << "/****************** Dog tests ************************/" << std::endl;
	std::cout << "// DOG CONSTRUCTORS" << std::endl;
	Animal		*_Dog = new Dog;
	std::cout << "this animal type is " << _Dog->getType() << std::endl;
	std::cout << "// DOG MAKESOUND" << std::endl;
	_Dog->makeSound();
	std::cout << std::endl << "************************************************************" << std::endl;
	std::cout << std::endl << "/****************** Wrong Animal tests ************************/" << std::endl;
	std::cout << "// WRONG ANIMAL CONSTRUCTORS" << std::endl;
	WrongAnimal	wa1;
	std::cout << "this animal type is " << wa1.getType() << std::endl;
	std::cout << "// WRONG ANIMAL MAKESOUND" << std::endl;
	wa1.makeSound();
	std::cout << std::endl << "/****************** Wrong Cat tests ************************/" << std::endl;
	std::cout << "// WRONG CAT CONSTRUCTORS" << std::endl;
	WrongAnimal		*not_cat = new WrongCat;
	std::cout << "this animal type is " << not_cat->getType() << std::endl;
	std::cout << "// WRONG CAT MAKESOUND" << std::endl;
	not_cat->makeSound();
    std::cout << std::endl << "************************************************************" << std::endl;
	std::cout << std::endl << "///// ALL DESTRUCTORS /////" << std::endl;
    delete _Cat;
    delete _Dog;
    delete not_cat;
	return (0);
}