#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl {
    private :
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
        void (Harl::*complaints[4])(void);

    public :
        Harl();
        void filterComplaints( std::string level );
        
};

#endif