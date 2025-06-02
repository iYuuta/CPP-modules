#include "Harl.hpp"

Harl::Harl() {
    complaints[0] = &Harl::debug;
    complaints[1] = &Harl::info;
    complaints[2] = &Harl::warning;
    complaints[3] = &Harl::error;
}

void Harl::debug(void) {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void) {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::filterComplaints( std::string level ) {
    int index = -1;
    std::string lvl[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++) {
        if (lvl[i] == level) {
            index = i;
            break ;
        }
    }
    switch (index) {
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            (this->*complaints[0])();
            std::cout << std::endl;
            //fallthrough
        case 1:
            std::cout << "[ INFO ]" << std::endl;
            (this->*complaints[1])();
            std::cout << std::endl;
            //fallthrough
        case 2:
            std::cout << "[ WARNING ]" << std::endl;
            (this->*complaints[2])();
            std::cout << std::endl;
            //fallthrough
        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            (this->*complaints[3])();
            std::cout << std::endl;
            break;
        default :
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}