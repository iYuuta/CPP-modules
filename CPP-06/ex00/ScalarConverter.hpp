#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>

enum types {
    INT,
    CHAR,
    FLOAT,
    DBL,
    SPEC,
    INV,
};

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& copy);
    public:
        ScalarConverter& operator=(const ScalarConverter& copy);
        ~ScalarConverter();
        static void convert(const std::string& str);
};

int getType(const std::string& str);
void convertDouble(const char *str);
void convertChar(const char *str);
void convertFloat(const char *str);
void convertInt(const char *str);
void specialCase(const std::string& str);
void invalidCase();
bool check_limit(const char *str);
