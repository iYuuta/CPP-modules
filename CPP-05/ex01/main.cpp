#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat john(111, "John snow");
	Bureaucrat darth(1, "darth vader");
	Bureaucrat paul(57, "paul atreides");
	Form a("invade the vale", 110, 11);
	Form b("invest in bitcoin", 150, 150);
	Form c("order 66", 1, 1);

	std::cout << "trying to sign forms without enough grades\n" << std::endl;
	{
		john.signForm(a);
		john.signForm(c);
	}
	std::cout << "\ntrying to sign forms with enough grades\n" << std::endl;
	{
		paul.signForm(b);
		john.signForm(a);
		darth.signForm(c);
	}
}