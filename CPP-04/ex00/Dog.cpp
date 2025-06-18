#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    std::cout << "A Dog has joined the lobby" << std::endl;
}

Dog::~Dog() {
    std::cout << "A Dog has left the lobby" << std::endl;
}

Dog::Dog(const Dog& copy): Animal(copy) {
    std::cout << "A Dog has duplicated itself" << std::endl;
    this->type = copy.type;
}

Dog& Dog::operator=(const Dog& _Dog) {
    if (this == &_Dog)
        return *this;
    this->type = _Dog.type;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "idk dog sound" << std::endl;
}