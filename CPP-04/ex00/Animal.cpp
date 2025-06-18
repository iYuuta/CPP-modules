#include "Animal.hpp"

Animal::Animal(): type("unkown") {
    std::cout << "An animal of an unknown type has appeared" << std::endl;
}

Animal::~Animal() {
    std::cout << "The unkown animal has fled" << std::endl;
}

Animal::Animal(const Animal& copy) {
    this->type = copy.type;
    std::cout << "A clone of an unkown animal has appeared" << std::endl;
}

Animal& Animal::operator=(const Animal& Animal) {
    if (this == &Animal)
        return *this;
    this->type = Animal.type;
    return *this;
}

void Animal::makeSound() const {
    std::cout << "weird animal sound" << std::endl;
}

std::string& Animal::getType() {
    return type;
}
