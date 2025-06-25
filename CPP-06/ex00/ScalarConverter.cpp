#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
    (void)copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy) {
    (void)copy;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& str) {
    int type;

    type = getType(str);
    if (type == INT || type == FLOAT || type == DBL) {
        if (!check_limit(str.c_str()))
            type = INV;
    }
    switch (type) {
        case INT :
            convertInt(str.c_str());
            break;
        case CHAR :
            convertChar(str.c_str());
            break;
        case FLOAT :
            convertFloat(str.c_str());
            break;
        case DBL :
            convertDouble(str.c_str());
            break;
        case SPEC :
            specialCase(str);
            break;
        default:
            invalidCase();
            break;
    }
}