#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>
#include <iomanip>
#include <exception>

class BitcoinExchange {
    private:
        std::map<unsigned long, float> btc;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        void parseDB(std::ifstream& file);
        float getvalue(unsigned long index);
        class FailedToOpenFile : public std::exception {
            public :
                const char *what() const throw() ;
        };
};

unsigned long get_date(std::string& str, int index);
float get_value(std::string& str, int index);