#include "Cat.hpp"

Cat::Cat() {
    type = "cat";
    _Brain = new Brain;
    std::cout << "A cat has joined the lobby" << std::endl;
}

Cat::~Cat() {
    delete _Brain;
    std::cout << "A cat has left the lobby" << std::endl;
}

Cat::Cat(const Cat& copy): Animal(copy) {
    std::cout << "A cat has duplicated itself" << std::endl;
    this->type = copy.type;
    this->_Brain = new Brain(*copy._Brain);
}

Cat& Cat::operator=(const Cat &Cat) {
    if (this == &Cat)
        return *this;
    this->type = Cat.type;
    *this->_Brain = *Cat._Brain;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "meooow" << std::endl;
}
