#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("unkown") {
    std::cout << "An impostor of an unknown type has appeared" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "The impostor has fled" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) {
    this->type = copy.type;
    std::cout << "A clone of an impostor has appeared" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& WrongAnimal) {
    if (this == &WrongAnimal)
        return *this;
    this->type = WrongAnimal.type;
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "weird impostor sound" << std::endl;
}

std::string& WrongAnimal::getType() {
    return type;
}
