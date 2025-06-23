#pragma once

#include "AForm.hpp"
#include <fstream>

#define TREE "          &&& &&  & &&\n      && &\\/&\\|& ()|/ @, &&\n      &\\/(/&/&||/& /_/)_&/_&\n   &() &\\/&|()|/&\\/ '%\" & ()\n  &_\\_&&_\\ |& |&&/&__%_/_& &&\n&&   && & &| &| /& & % ()& /&&\n ()&_---()&\\&\\|&&-&&--%---()~\n     &&     \\|||\n             |||\n             |||\n             |||\n       , -=-~  .-^- _\n"

class ShrubberyCreationForm : public AForm {
    private:
		std::string	_target;
    public:
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& copy);
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
        void executeForm(Bureaucrat const & executor) const ;
};

std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm const &form);
