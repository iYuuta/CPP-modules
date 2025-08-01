#pragma once

#include <stack>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

class RPN {
    private:
        std::stack<double>	_stack;
        double				_result;
    public:
        RPN();
        RPN(const RPN& other);
        ~RPN();
        RPN&	operator=(const RPN& other);
		void	run(std::string args);
};

