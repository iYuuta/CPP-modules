#include "PmergeMe.hpp"

int main(int ac, char **av) {
    if (ac > 1) {
        try {
            PmergeMe yuta(ac, av);
            yuta.run();
        }
        catch (std::string err) {
            std::cerr << "Error: " << err << std::endl;
            return 1;
        }
    }
    else {
        std::cerr << "Error: invalid number of arguments" << std::endl;
        return 1;
    }
}