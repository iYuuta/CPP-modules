#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact{
    private :
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string number;
        std::string secret;
        int         index;
    public :
        Contact();
        void        add_first_name(const std::string& name);
        void        add_last_name(const std::string& name);
        void        add_nickname(const std::string& name);
        void        add_number(const std::string& number);
        void        add_darkest_secret(const std::string& secret);
        void        set_index(int index);
        std::string trim_text(std::string str);
        void        decrement_index();
        void        print_contact();
        int         get_index();
        void        print_info();
};

#endif