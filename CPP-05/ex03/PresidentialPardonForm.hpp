#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
    private:
		std::string	_target;
    public:
        PresidentialPardonForm();
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& copy);
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
        void executeForm(Bureaucrat const & executor) const ;
};

std::ostream	&operator<<(std::ostream &out, PresidentialPardonForm const &form);