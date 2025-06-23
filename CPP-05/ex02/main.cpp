#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	ShrubberyCreationForm shrubbery("Erdtree");
	RobotomyRequestForm robotomy("Morty");
	PresidentialPardonForm pardon("Giga chad");
	Bureaucrat anakin(150, "Anakin");
	Bureaucrat john(120, "John snow");
	Bureaucrat larry(3, "larry");

	std::cout << "bureaucrats\n" << std::endl;
	std::cout << anakin << std::endl;
	std::cout << john << std::endl;
	std::cout << larry << std::endl;
	std::cout << "\nforms\n" << std::endl;
	std::cout << shrubbery << std::endl;
	std::cout << robotomy << std::endl;
	std::cout << pardon << std::endl;
	std::cout << "\ntrying to execute forms without being signed\n" << std::endl;
	{
		
		larry.executeForm(shrubbery);
		larry.executeForm(robotomy);
		larry.executeForm(pardon);
	}
	std::cout << "\ntrying to execute forms without enough grades\n" << std::endl;
	{
		john.signForm(shrubbery);
		anakin.executeForm(shrubbery);
	}
	std::cout << "\ntrying to sign or execute forms with enough grades\n" << std::endl;
	{
		larry.signForm(robotomy);
		larry.signForm(pardon);
		larry.signForm(shrubbery);
		larry.executeForm(shrubbery);
		larry.executeForm(robotomy);
		larry.executeForm(pardon);
	}
	return (0);
}