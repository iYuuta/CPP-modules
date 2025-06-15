#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    _Brain = new Brain;
    std::cout << "A Dog has joined the lobby" << std::endl;
}

Dog::~Dog() {
    delete _Brain;
    std::cout << "A Dog has left the lobby" << std::endl;
}

Dog::Dog(const Dog& copy): Animal(copy) {
    std::cout << "A Dog has duplicated itself" << std::endl;
    this->_Brain = new Brain(*copy._Brain);
    this->type = copy.type;
}

Dog& Dog::operator=(const Dog& _Dog) {
    if (this == &_Dog)
        return *this;
    this->type = _Dog.type;
    delete this->_Brain;
    *this->_Brain = *_Dog._Brain;
    return *this;
}

void Dog::makeSound() {
    std::cout << "idk dog sound" << std::endl;
}