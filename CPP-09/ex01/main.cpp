#include "RPN.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Error: invalid arguments\n";
        return 1;
    }
    RPN calculator;
    try {
        calculator.run(av[1]);
    }
    catch (std::string error) {
        std::cerr << error << std::endl;
        return 1;
    }
}