#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(int grade) : _name("default") {
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(int grade, const std::string& name) : _name(name) {
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy): _name(copy.getName()) {
    _grade = copy.getGrade();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
    if (this == &src)
        return *this;
    this->_grade = src.getGrade();
    return *this;
}

const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::upgrade() {
    if (_grade > 1)
        _grade--;
    else
        throw GradeTooHighException();
}

void Bureaucrat::downgrade() {
    if (_grade < 150)
        _grade++;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, Bureaucrat& _bureaucrat) {
    out << _bureaucrat.getName() << ", bureaucrat grade " << _bureaucrat.getGrade();
    return out;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}
