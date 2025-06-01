#include "Harl.hpp"

int main(int ac, char **av) {
    if (ac != 2)
    {
        std::cerr << "invalid input -> ./harlFilter <level>" << std::endl;
        return (1);
    }
    Harl harl;

    harl.filterComplaints(av[1]);
}