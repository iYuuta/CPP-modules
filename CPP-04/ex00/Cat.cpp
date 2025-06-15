#include "Cat.hpp"

Cat::Cat() {
    type = "cat";
    std::cout << "A cat has joined the lobby" << std::endl;
}

Cat::~Cat() {
    std::cout << "A cat has left the lobby" << std::endl;
}

Cat::Cat(const Cat& copy): Animal(copy) {
    std::cout << "A cat has duplicated itself" << std::endl;
    this->type = copy.type;
}

Cat& Cat::operator=(const Cat &Cat) {
    if (this == &Cat)
        return *this;
    this->type = Cat.type;
    return *this;
}

void Cat::makeSound() {
    std::cout << "meooow" << std::endl;
}