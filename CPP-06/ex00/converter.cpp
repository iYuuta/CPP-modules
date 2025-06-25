#include "ScalarConverter.hpp"

bool check_limit(const char *str) {
	if (atol(str) < -2147483648)
		return false;
	if (atol(str) > 2147483647)
		return false;
	return true;
}

void convertInt(const char *str) {
	char c;
	int i = atoi(str);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

	if (i >= 0 && i < 128) {
		c = i;
		if (isprint(c))
			std::cout << "char: '" << c << "'\n";
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "int: " << i << std::endl	<< "float: " << f << "f" << std::endl << "double: " << d << std::endl;
}

void convertFloat(const char *str) {
    char c;
	float f = atof(str);
	int i = atoi(str);
	double d = atof(str);
	if (i >= 0 && i < 128) {
		c = i;
		if (isprint(c))
			std::cout << "char: '" << c << "'\n";
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "int: " << i << std::endl	<< "float: " << f << "f" << std::endl << "double: " << d << std::endl;
}

void convertChar(const char *str) {
    char c;
	if (*str == '\'' || *str == '\"')
		c = str[1];
	else
		c = *str;
	int i = c;
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);
	if (i >= 0 && i < 128) {
		c = i;
		if (isprint(c))
			std::cout << "char: '" << c << "'\n";
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "int: " << i << std::endl	<< "float: " << f << "f" << std::endl << "double: " << d << std::endl;
}

void convertDouble(const char *str) {
    char c;
	float f = atof(str);
	int i = atoi(str);
	double d = atof(str);
	if (i >= 0 && i < 128) {
		c = i;
		if (isprint(c))
			std::cout << "char: '" << c << "'\n";
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "int: " << i << std::endl	<< "float: " << f << "f" << std::endl << "double: " << d << std::endl;
}

void invalidCase() {
	std::cout << "char: impossible\n" << "int: impossible\n" << "float: impossible\n" << "double: impossible\n";
}

void specialCase(const std::string& str) {
	if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible" << std::endl << "int: impossible" <<
		std::endl << "float: nanf" << std::endl << "double: nan" << std::endl;
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "char: impossible" << std::endl << "int: impossible"
		<< std::endl << "float: +inff" << std::endl << "double: +inf" << std::endl;
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl << "int: impossible"
		<< std::endl << "float: -inff" << std::endl << "double: -inf" << std::endl;
	}
}

int getType(const std::string& str) {
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
		return SPEC;
    if (str.length() == 1 && !isdigit(str[0]))
		return CHAR;
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return CHAR;
    int i = 0;
    if (str[i] == '-') 
        i++;
    while (str[i] && isdigit(str[i]) && i < 11)
        i++;
    if (!str[i])
        return INT;
    else if (str[i++] == '.' && (long unsigned int)i < str.length()) {
		while (str[i] && isdigit(str[i]))
			i++;
	if ((long unsigned int)i == str.length())
        return DBL;
	else if (str[i++] == 'f' && !str[i])
		return FLOAT;
    }
    return INV;
}
