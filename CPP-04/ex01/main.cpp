#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	Animal *animals[100];

	std::cout << "bringing in the dogs" << std::endl;
	for (int i = 0; i < 50; i++)
		animals[i] = new Dog();
	std::cout << "now the cats" << std::endl;
	for (int i = 50; i < 100; i++)
		animals[i] = new Cat();
	std::cout << "kick them all out" << std::endl;
	for (int i = 0; i < 100; i++)
		delete animals[i];
	return (0);
}