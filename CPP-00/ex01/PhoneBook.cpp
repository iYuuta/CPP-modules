#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    index = 0;
}

int PhoneBook::get_index() {
    return index;
}

void PhoneBook::set_index() {
    index++;
}

void PhoneBook::update_index() {
    for (int i = 0; i < 8; i++)
        contact[i].decrement_index();
}

std::string PhoneBook::trim(std::string buffer) {
    
    std::size_t start = 0;
    std::size_t end = buffer.length();
    while (start < buffer.length() && std::isspace((buffer[start])))
        ++start;
    while (end > start && std::isspace((buffer[end - 1])))
        --end;
    return buffer.substr(start, end - start);
}

bool is_valid_index(std::string str) {
    std::string buffer;
    for (size_t i = 0; i < str.length(); i++) {
        if (!isdigit(str[i])) {
            std::cout << "Invalid index. Please try again.\n";
            return false;
        }
        int num = 0;
        std::stringstream buffer(str);
        buffer >> num;
        if (num <= 0 || num > 8) {
            std::cout << "Index is out of range. Please try again.\n";
            return false;
        }
    }
    return true;
}

void    PhoneBook::print_contacts() {
    if (index == 0) {
        std::cout << "PhoneBook is empty" << std::endl;
        return ;
    }
    std::cout << "     index|first name| last name|  nickname|" << std::endl;
    for (int i = 1; i < 9; i++) {
        for (int j = 0; j < 8; j++) {
            if (contact[j].get_index() == i)
                contact[j].print_contact();
        }
    }
    print_contact_info();
}

int    PhoneBook::print_contact_info() {
    std::string buffer;
    int index = 0;
    do {
        std::cout << "Enter an index: ";
        std::getline(std::cin, buffer);
        if (std::cin.eof()) {
            std::cout << std::endl;
            return (1);
        }
        else if (!is_valid_index(buffer)) {
            buffer.clear();
        }
    } while (buffer.empty());
    std::stringstream str(buffer);
    str >> index;
    for (int i = 0 ; i <= 8; i++) {
        if (contact[i].get_index() == index)
        {
            contact[i].print_info();
            return (0);
        }
        else if (i == 8)
            std::cout << "Contact isn't available" << std::endl;
    }
    return (0);
}


std::string PhoneBook::is_valid_input() {
    std::string buffer;
    
    std::getline(std::cin, buffer);
    if (std::cin.eof()) {
        std::cout << std::endl;
        return buffer;
    }
    else if (buffer.empty())
    return buffer;
    for (size_t i = 0; i < buffer.length(); i++) {
        if (isspace(buffer[i]))
        buffer[i] = ' ';
    }
    return trim(buffer);
}

int    PhoneBook::add_contact(int i){
    std::string buffer;


    if (get_index() >= 8)
    {
        update_index();
        i = i % 8;
    }
    do {
        std::cout << "Enter a first name: ";
        buffer = is_valid_input();
        if (std::cin.eof())
            return 1;
        if (buffer.empty())
            std::cout << "A field can't be empty. Please try again.\n";
    } while (buffer.empty());
    contact[i].add_first_name(buffer);
    do {
        std::cout << "Enter a last name: ";
        buffer = is_valid_input();
        if (std::cin.eof())
            return 1;
        if (buffer.empty())
            std::cout << "A field can't be empty. Please try again.\n";
    } while (buffer.empty());
    contact[i].add_last_name(buffer);
    do {
        std::cout << "Enter a nickname: ";
        buffer = is_valid_input();
        if (std::cin.eof())
            return 1;
        if (buffer.empty())
            std::cout << "A field can't be empty. Please try again.\n";
    } while (buffer.empty());
    contact[i].add_nickname(buffer);
    do {
        std::cout << "Enter a number: ";
        buffer = is_valid_input();
        if (std::cin.eof())
            return 1;
        if (buffer.empty())
            std::cout << "A field can't be empty. Please try again.\n";
    } while (buffer.empty());
    contact[i].add_number(buffer);
    do {
        std::cout << "Enter a darkest secret: ";
        buffer = is_valid_input();
        if (std::cin.eof())
            return 1;
        if (buffer.empty())
            std::cout << "A field can't be empty. Please try again.\n";
    } while (buffer.empty());
    contact[i].add_darkest_secret(buffer);
    contact[i].set_index(index + 1);
    set_index();
    return (0);
}
