#include "Harl.hpp"

int main() {
    Harl _harl;

    std::cout << "LEVEL 1" << std::endl;
    _harl.complain("debug");
    std::cout << "LEVEL 2" << std::endl;
    _harl.complain("info");
    std::cout << "LEVEL 3" << std::endl;
    _harl.complain("warning");
    std::cout << "LEVEL 4" << std::endl;
    _harl.complain("error");
}