#include "AForm.hpp"

AForm::AForm(): _name("default"), _signed(false), _sign_requirement(125), _execute_requirement(125) {}

AForm::~AForm() {}

AForm::AForm(const std::string& name, int sign_req, int exe_req): _name(name), _sign_requirement(sign_req), _execute_requirement(exe_req) {
    _signed = false;
}

AForm::AForm(const AForm& copy): _name(copy._name), _signed(copy._signed),
_sign_requirement(copy._sign_requirement), _execute_requirement(copy._execute_requirement) {}

AForm& AForm::operator=(const AForm& copy) {
    if (this == &copy)
        return *this;
    _signed = copy._signed;
    return *this;
}

void AForm::beSigned(const Bureaucrat& _bureaucrat) {
    if (_bureaucrat.getGrade() <= this->_sign_requirement) {
        _signed = true;
        std::cout << _bureaucrat.getName() << " signed " << this->_name << std::endl;
        return ;
    }
    else
        throw GradeTooLowException();
}

const std::string& AForm::getName() const {
    return this->_name;
}

bool AForm::isSigned() const {
    return this->_signed;
}

int   AForm::getSignReq() const {
    return this->_sign_requirement;
}

int   AForm::getExeReq() const {
    return this->_execute_requirement;

}

const char* AForm::GradeTooHighException::what() const throw() {
    return "bureaucrat grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "bureaucrat grade is too low";
}

const char* AForm::FormIsNotSigned::what() const throw() {
    return "Form is not signed";
}

void AForm::execute(const Bureaucrat& executor) const {
    if (!this->_signed)
        throw FormIsNotSigned();
    else if (executor.getGrade() > this->_execute_requirement)
        throw GradeTooLowException();
    else {
        executeForm(executor);
        std::cout << executor.getName() << " executed " << this->_name << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, AForm& _Aform) {
    out << _Aform.getName() << ", AForm signed status " << _Aform.isSigned() << " AForm sign requirement "
    << _Aform.getSignReq() << " AForm Execution requirement " << _Aform.getExeReq();
    return out;
}