#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;

    std::string str;
    while (true)
    {
        std::cout << "Enter a command: ";
        std::getline(std::cin, str);
        str = phonebook.trim(str);
        if (std::cin.eof()) {
            std::cout << std::endl;
            return (0);
        } 
        else if (str.empty())
            continue;
        else if (str == "ADD") {
            if (phonebook.add_contact(phonebook.get_index()))
                return (0);
        }
        else if (str == "EXIT")
            return (0);
        else if (str == "SEARCH") {
            phonebook.print_contacts();
        }
        else
            std::cout << "Not a valid command" << std::endl;
    }
}