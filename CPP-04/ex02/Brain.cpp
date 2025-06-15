#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain default constructor has been called" << std::endl;
    for (int i = 0; i < 100; i++) {
        ideas[i] = "nothing";
    }
};

Brain::~Brain() {
    std::cout << "Brain default destructor has been called" << std::endl;
}

Brain::Brain(const Brain& copy) {
    std::cout << "Brain copy constructor has been called" << std::endl;
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = copy.ideas[i];
    }
}

Brain& Brain::operator=(const Brain& _Brain) {
    if (this == &_Brain)
        return *this;
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = _Brain.ideas[i];
    }
    return *this;
}
