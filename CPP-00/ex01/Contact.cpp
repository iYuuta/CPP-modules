#include "Contact.hpp"

Contact::Contact() {
    index = 0;
}

void Contact::add_first_name(const std::string& name) {
    first_name = name;
}

void Contact::add_last_name(const std::string& name) {
    last_name = name;
}

void Contact::add_nickname(const std::string& name) {
    nickname = name;
}
void Contact::add_number(const std::string& number) {
    this->number = number;
}

void Contact::add_darkest_secret(const std::string& secret) {
    this->secret = secret;
}

void Contact::set_index(int index) {
    if (index <= 8)
        this->index = index;
    else
        this->index = 8;
}

int Contact::get_index() {
    return index;
}

void Contact::decrement_index() {
    index--;
}

std::string Contact::trim_text(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + '.');
    return (str);
}

void Contact::print_contact()
{
    std::cout << std::right << std::setw(10) << index << "|" << std::setw(10)
    << trim_text(first_name) << "|" << std::setw(10) << trim_text(last_name) << "|" << std::setw(10)
    << trim_text(nickname) << "|" << std::setw(10) << std::endl;
}

void Contact::print_info() {
    std::cout << "first name: " << first_name << std::endl
    << "last name: " << last_name << std::endl
    << "nickname: " << nickname << std::endl
    << "number: " << number << std::endl
    << "darkest secret: " << secret << std::endl;
}