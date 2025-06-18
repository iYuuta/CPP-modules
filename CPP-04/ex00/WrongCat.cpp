#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    type = "car";
    std::cout << "an impostor cat has joined the lobby" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "an impostor cat has left the lobby" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy): WrongAnimal(copy) {
    std::cout << "an impostor cat has dupliWrongCated itself" << std::endl;
    this->type = copy.type;
}

WrongCat& WrongCat::operator=(const WrongCat &WrongCat) {
    if (this == &WrongCat)
        return *this;
    this->type = WrongCat.type;
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "vrooom" << std::endl;
}