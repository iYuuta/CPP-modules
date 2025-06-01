#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "The memory address of the string-> " << &str << std::endl << "The memory address held by pointer-> " << stringPTR
    << std::endl << "The memory address held by reference-> " << &stringREF << std::endl;

    std::cout << "The value of the string-> " << str << std::endl << "The value pointed to by the pointer-> " << *stringPTR
    << std::endl << "The value pointed to by the reference-> " << stringREF << std::endl;
}