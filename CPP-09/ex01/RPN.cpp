#include "RPN.hpp"

RPN::RPN(): _result(0) {}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		this->_result = other._result;
		this->_stack = other._stack;
	}
	return *this;
}

RPN::RPN(const RPN& other) {
	*this = other;
}

void RPN::run(std::string args) {
	std::istringstream iss(args);
	std::string token;
	double fst, sec;

	while (iss >> token) {
		if (token.length() == 1 && std::string("+-*/").find(token[0]) != std::string::npos) {
			fst = _stack.top(); _stack.pop();
			sec = _stack.top(); _stack.pop();
			switch (token[0]) {
				case '+':
					_stack.push(sec + fst);
					break;
				case '-':
					_stack.push(sec - fst);
					break;
				case '*':
					_stack.push(sec * fst);
					break;
				case '/':
					if (fst == 0)
						throw std::string("Division by zero");
					_stack.push(sec / fst);
					break;
			}
		}
		else if (token.length() == 1 && std::isdigit(token[0]))
			_stack.push(std::atol(token.c_str()));
		else
			throw std::string("Error");
	}
	if (_stack.size() != 1)
		throw std::string("Error");
	std::cout << _stack.top() << std::endl;
}
