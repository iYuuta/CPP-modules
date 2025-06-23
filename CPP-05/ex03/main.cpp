#include "Intern.hpp"

int main() {
	Intern mikey;
	AForm* f1;
	Bureaucrat luther(1, "marten luther king");

	try {
		f1 = mikey.makeForm("robotomy request", "Bender");
	}
	catch (std::exception& exc) {
		std::cerr << "Intern failed because its an " << exc.what() << std::endl;
	}
	luther.signForm(*f1);
	luther.executeForm(*f1);
	delete f1;
	return (0);
}