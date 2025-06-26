#include <string>
#include <iostream>
#include "iter.hpp"

void cprint(const char c) {
    std::cout << c;
}

void print(char c) {
    std::cout << c;
}

int main() {
    const char str[] = "hello";
    ::iter(str, 5, print);
    std::cout  << std::endl;
    ::iter(str, 5, cprint);
    std::cout  << std::endl;
}