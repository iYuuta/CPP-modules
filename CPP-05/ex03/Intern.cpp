#include "Intern.hpp"

Intern::Intern() {};

Intern::Intern(const Intern& copy) {
    *this = copy;
};

Intern::~Intern() {};

Intern& Intern::operator=(const Intern& copy) {
    if (this == &copy)
        return *this;
    return *this;
}

static AForm	*makePardon(const std::string& target) {
	return (new PresidentialPardonForm(target));
}

static AForm	*makeRobot(const std::string& target) {
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubbery(const std::string& target) {
	return (new ShrubberyCreationForm(target));
}

const char *Intern::FormNotFound::what() const throw() {
    return "Invalid Form";
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) {
    const char* type[] = {"robotomy request", "PresidentialPardon request", "ShrubberyCreation request"};
    AForm* (*func[3])(const std::string&) = {&makeRobot, &makePardon, &makeShrubbery};

    for (int i = 0; i < 3; i++) {
        if (name == type[i]) {
            return func[i](target);
        }
    }
    throw FormNotFound();
    return NULL;
}