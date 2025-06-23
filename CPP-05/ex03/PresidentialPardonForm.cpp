#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("presidential pardon", 25, 5), _target("none") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm("presidential pardon", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy): AForm(copy), _target(copy._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) {
    if (this != &copy)
        _target = copy._target;
    return *this;
}

void PresidentialPardonForm::executeForm(Bureaucrat const & executor) const  {
    if (executor.getGrade() <= 5) {
        std::cout << this->_target <<" has been pardoned by Zaphod Beeblebrox" << std::endl;
    }
}

std::ostream	&operator<<(std::ostream &out, PresidentialPardonForm const &form)
{
	out << form.getName() << " form, signed: " << form.isSigned() << ", sign grade: " << form.getSignReq() << ", exec grade: " << form.getExeReq();
    return out;
}