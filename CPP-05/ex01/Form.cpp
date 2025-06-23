#include "Form.hpp"

Form::Form(): _name("default"), _signed(false), _sign_requirement(125), _execute_requirement(125) {}

Form::~Form() {}

Form::Form(const std::string& name, int sign_req, int exe_req): _name(name), _sign_requirement(sign_req), _execute_requirement(exe_req) {
    _signed = false;
}

Form::Form(const Form& copy): _name(copy._name), _signed(copy._signed),
_sign_requirement(copy._sign_requirement), _execute_requirement(copy._execute_requirement) {}

Form& Form::operator=(const Form& copy) {
    if (this == &copy)
        return *this;
    _signed = copy._signed;
    return *this;
}

void Form::beSigned(const Bureaucrat& _bureaucrat) {
    if (_bureaucrat.getGrade() <= this->_sign_requirement) {
        _signed = true;
        std::cout << _bureaucrat.getName() << " signed " << this->_name << std::endl;
        return ;
    }
    else
        throw GradeTooLowException();
}

const std::string& Form::getName() {
    return this->_name;
}

bool Form::isSigned() {
    return this->_signed;
}

int   Form::getSignReq() {
    return this->_sign_requirement;
}

int   Form::getExeReq() {
    return this->_execute_requirement;

}

const char* Form::GradeTooHighException::what() const throw() {
    return "bureaucrat grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "bureaucrat grade is too low";
}

std::ostream& operator<<(std::ostream& out, Form& _form) {
    out << _form.getName() << ", Form signed status " << _form.isSigned() << " Form sign requirement "
    << _form.getSignReq() << " Form Execution requirement " << _form.getExeReq();
    return out;
}