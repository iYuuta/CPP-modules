#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat tarnished(2, "tarnished");
	Bureaucrat mclovin(149, "McLovin");
	
	std::cout << "bureaucrats\n" << std::endl;
	std::cout << tarnished << std::endl;
	std::cout << mclovin << std::endl;

	std::cout << "\nupgrade tarnished\n" << std::endl;
	tarnished.upgrade();
	std::cout << tarnished << std::endl;
	std::cout << "\ndowngrade McLovin\n" << std::endl;
	mclovin.downgrade();
	std::cout << mclovin << std::endl;
	std::cout << "\nupgrade tarnished\n" << std::endl;
	try {
		tarnished.upgrade();
	}
	catch (std::exception& exc) {
		std::cerr << exc.what() << std::endl;
	}
	std::cout << "\ndowngrade McLovin\n" << std::endl;
	try {
		mclovin.downgrade();
	}
	catch (std::exception& exc) {
		std::cerr << exc.what() << std::endl;
	}
	return (0);
}
