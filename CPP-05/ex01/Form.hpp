#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool              _signed;
        const int         _sign_requirement;
        const int         _execute_requirement;

    public:
        Form();
        ~Form();
        Form(const Form& copy);
        Form& operator=(const Form& copy);
        Form(const std::string& name, int sign_req, int exe_req);
        bool isSigned();
        const std::string& getName();
        int   getSignReq();
        int   getExeReq();

        void beSigned(const Bureaucrat& _bureaucrat);
        class GradeTooHighException : public std::exception {
            public :
                const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public :
                const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, Form& _form);