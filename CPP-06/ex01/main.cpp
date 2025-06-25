#include "Serializer.hpp"

int main() {
    Data* ptr = new Data;
    uintptr_t raw;

    raw = Serializer::serialize(ptr);
    ptr = Serializer::deserialize(raw);
    std::cout << "pointer: " << ptr << "\nraw: " << raw << std::endl;
    delete ptr;
}