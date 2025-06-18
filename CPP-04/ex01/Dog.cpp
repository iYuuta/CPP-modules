#include "Dog.hpp"

Dog::Dog() {
    type = "dog";
    _Brain = new Brain;
    std::cout << "A dog has joined the lobby" << std::endl;
}

Dog::~Dog() {
    delete _Brain;
    std::cout << "A dog has left the lobby" << std::endl;
}

Dog::Dog(const Dog& copy): Animal(copy) {
    std::cout << "A dog has duplicated itself" << std::endl;
    this->type = copy.type;
    this->_Brain = new Brain(*copy._Brain);
}

Dog& Dog::operator=(const Dog &dog) {
    if (this == &dog)
        return *this;
    this->type = dog.type;
    *this->_Brain = *dog._Brain;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "idk dog sounds" << std::endl;
}
