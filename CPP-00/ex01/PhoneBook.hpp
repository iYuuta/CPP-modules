#include <iostream>
#include "Contact.hpp"
#include <sstream>

class PhoneBook {
    private:
        Contact contact[8];
        int index;
    public :
        PhoneBook();
        int         add_contact(int i);
        int         get_index();
        void        set_index();
        void        update_index();
        void        print_contacts();
        std::string is_valid_input();
        std::string trim(std::string buffer);
        int         print_contact_info();
} ;
