#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool              _signed;
        const int         _sign_requirement;
        const int         _execute_requirement;

    public:
        AForm();
        virtual ~AForm();
        AForm(const AForm& copy);
        AForm& operator=(const AForm& copy);
        AForm(const std::string& name, int sign_req, int exe_req);
        bool isSigned() const ;
        const std::string& getName() const ;
        int   getSignReq() const ;
        int   getExeReq() const ;

        void beSigned(const Bureaucrat& _bureaucrat);
        void execute(Bureaucrat const & executor) const ;
        virtual void executeForm(Bureaucrat const & executor) const = 0;
        class GradeTooHighException : public std::exception {
            public :
                const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public :
                const char *what() const throw();
        };
        class FormIsNotSigned : public std::exception {
            public :
                const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, AForm& _Aform);