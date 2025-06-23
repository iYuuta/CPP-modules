#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robot", 72, 45), _target("none")  {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("Robot", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy): AForm(copy), _target(copy._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
    if (this != &copy)
        _target = copy._target;
    return *this;
}

void RobotomyRequestForm::executeForm(Bureaucrat const & executor) const {
    srand((unsigned) time(NULL));
    if (executor.getGrade() <= 45) {
        std::cout << "*(drilling noise)*" << std::endl;
        if (std::rand() % 2 == 0)
            std::cout << this->_target << " has been robotomized successfully" << std::endl;
        else
            std::cout << this->_target << "'s robotomizing failed" << std::endl;
    }
}

std::ostream	&operator<<(std::ostream &out, RobotomyRequestForm const &form)
{
	out << form.getName() << " form, signed: " << form.isSigned() << ", sign grade: " << form.getSignReq() << ", exec grade: " << form.getExeReq();
    return out;
}