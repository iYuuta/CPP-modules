#include "BitcoinExchange.hpp"

int check_format(std::string str) {
    int i = 0;

    if (str.length() < 14)
        return 1;
    while (i < 4) {
        if (!isdigit(str[i]))
            return 1;
        i++;
    }
    if (str[i++] != '-')
        return 1;
    while (i < 7) {
        if (!isdigit(str[i]))
            return 1;
        i++;
    }
    if (str[i++] != '-')
        return 1;
    while (i < 10) {
        if (!isdigit(str[i]))
            return 1;
        i++;
    }
    if (str[i++] != ' ' || str[i++] != '|' || str[i++] != ' ')
        return 1;
    if (str[i] == '-' || str[i] == '+') {
		std::cerr << "Error: not a positive number\n";
		return (2);
        i++;
	}
    int counter = 0;
    while (str[i]) {
        if (!isdigit(str[i]) && str[i] != '.')
            return 1;
        if (str[i] == '.')
            counter++;
        if (counter == 2)
            return 1;
        i++;
    }
    return 0;
}

int check_date(std::string& str) {
	str.erase(std::remove(str.begin(), str.end(), '-'), str.end());
	unsigned long result = std::stoi(str);
	if (result > 20220329 || result < 20090102)
		return 1;
	long year, month, days;
	year = std::atol(str.substr(0, 4).c_str());
	month = std::atol(str.substr(4, 2).c_str());
	days = std::atol(str.substr(7, 2).c_str());
	// std::cout << result << std::endl << year << ' ' << month << ' ' << days << std::endl;
	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && days < 1 || days > 31)
		return 1;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && days < 1 && days > 30)
		return 1;
	if (month == 2 && days == 29 && (year != 2012 || year != 2016 || year != 2020))
		return 1;
	if (month == 2 && days > 29 || days < 1)
		return 1;
	return 0;
}

int check_input(std::string str) {
	int flag;
	flag = check_format(str);
	if (flag == 1) {
		std::cerr << "Error: bad input => " << str << std::endl;
		return flag;
	}
	if (flag == 2)
		return flag;
    std::string date;
    date = str.substr(0, 10);
    if (check_date(date)) {
		std::cerr << "Error: bad input => " << str << std::endl;
		return 1;
	}
    return 0;
}

int process_args(std::ifstream& readin, BitcoinExchange btc) {
    std::string buff;
    std::string tmpdate;
    std::string tmp;
    double value;
	unsigned long date;

    std::getline(readin, buff);
    if (buff != "date | value") {
        std::cerr << "invalid argument" << std::endl;
    }
    while (std::getline(readin, buff)) {
        if (check_input(buff))
			continue ;
		else if (atof(buff.substr(13, buff.length() - 12).c_str()) > 2147483647) {
			std::cerr << "Error: too large a number." << std::endl;
		}
		else {
			tmpdate = buff.substr(0, 10);
			std::cout << tmpdate << " => ";
			tmpdate.erase(std::remove(tmpdate.begin(), tmpdate.end(), '-'), tmpdate.end());
			date = std::stoi(tmpdate);
			tmp = buff.substr(13, buff.length() - 12);
			value = atof(tmp.c_str());
			std::cout << tmp << " = " << btc.getvalue(date) * value << std::endl;
			std::cout << btc.getvalue(date) << std::endl;
		}
    }
	return 0;
}

int main(int ac, char **av) {
    std::ifstream readin;

	std::cout << std::fixed << std::setprecision(2);
    if (ac != 2) {
        std::cerr << "invalid arguments\n";
        return 1;
    }
    readin.open(av[1], std::ifstream::in);
    if (!readin.is_open()) {
        std::cerr << "an error accured while opening the file\n";
        return 1;
    }
    try {
        BitcoinExchange btc;
		process_args(readin, btc);
    }
    catch (std::exception& exc) {
        std::cerr << "error: " << exc.what() << std::endl;
        return 1;
    }	
	return 0;
}
