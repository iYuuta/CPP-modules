#pragma once

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat {
    private:
        const std::string _name;
        int               _grade;
    public:
        Bureaucrat();
        Bureaucrat(int grade);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat(int grade, const std::string& name);
        ~Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat& src);
        const std::string& getName() const ;
        int getGrade() const ;
        void upgrade();
        void downgrade();

    class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw();
    };
    class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, Bureaucrat& _bureaucrat);
