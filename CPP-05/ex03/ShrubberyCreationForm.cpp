#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery", 145, 137), _target("none")  {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("Shrubbery", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy): AForm(copy), _target(copy._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {
    if (this != &copy)
        _target = copy._target;
    return *this;
}

void ShrubberyCreationForm::executeForm(Bureaucrat const & executor) const  {
    if (executor.getGrade() <= 137) {
        std::ofstream outfile;

        outfile.open((this->_target + "_shrubbery").c_str());
        if (outfile.fail()) {
		    std::cout << "Could not open output file" << std::endl;
		    return ;
	    }
        outfile << TREE;
        outfile.close();
	    std::cout << executor.getName() << " successfully created a shrubbery" << std::endl;
    }
}

std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm const &form)
{
	out << form.getName() << " form, signed: " << form.isSigned() << ", sign grade: " << form.getSignReq() << ", exec grade: " << form.getExeReq();
    return out;
}