#pragma once

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
    private:
		std::string	_target;
    public:
        RobotomyRequestForm();
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& copy);
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
        void executeForm(Bureaucrat const & executor) const ;
};

std::ostream	&operator<<(std::ostream &out, RobotomyRequestForm const &form);