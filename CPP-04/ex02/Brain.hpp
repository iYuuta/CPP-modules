#pragma once

#include <string>
#include <iostream>

class Brain {
    private :
        std::string ideas[100];

    public :
        Brain();
        ~Brain();
        Brain(const Brain& copy);
        Brain& operator=(const Brain& _Brain);
};