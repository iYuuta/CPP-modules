#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange() {}

double BitcoinExchange::getValue(std::string& str, int index) {
	return atof(str.substr(index + 1).c_str());
}

unsigned long BitcoinExchange::getDate(std::string& str, int index) {
	std::string tmp = str.substr(0, index);
	tmp.erase(std::remove(tmp.begin(), tmp.end(), '-'), tmp.end());
	unsigned long result = std::atoll(tmp.c_str());
	return result;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		this->_btc = other._btc;
	}
	return *this;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	*this = other;
}

BitcoinExchange::BitcoinExchange() {
	std::ifstream	db("data.csv");
	std::string		buffer;
	size_t			index;

	if (!db.is_open())
		throw(std::string) "could not open a file.";
	std::getline(db, buffer);
	while (std::getline(db, buffer)) {
		index = buffer.find(",");
		this->_btc.insert(std::make_pair(getDate(buffer, index), getValue(buffer, index)));
	}
	db.close();
}

void BitcoinExchange::isDateValid(int year, int month, int day) {
	int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month < 1 || month > 12 || day < 1)
		throw (std::string) "bad input => ";
	if (month == 2 && (year == 2012 || year == 2016 || year == 2020))
		months[1] = 29;
	if (year < 2009 || (year == 2009 && month == 1 && day < 2))
		throw(std::string) "invalid date";
	if (day > months[month - 1])
		throw(std::string) "invalid date";
	if (year > 2022 || (year == 2022 && month == 3 && day > 29))
		throw(std::string) "invalid date";
	_date = year * 10000 + month * 100 + day;
}

void BitcoinExchange::isValueValid(float value) {
	if (value > 1000)
		throw (std::string) "too large a number.";
	if (value < 0)
		throw (std::string) "not a positive number.";
	_value = value;
}

const std::string BitcoinExchange::floatToString(float value) {
    std::ostringstream tmp;
    tmp << std::fixed << std::setprecision(2) << value;
    std::string s = tmp.str();
    s.erase(s.find_last_not_of('0') + 1, std::string::npos);
    s.erase(s.find_last_not_of('.') + 1, std::string::npos);
    return s;
}

void BitcoinExchange::printResult(const std::string& date) {
	std::map<unsigned long, double>::iterator it;

	it = this->_btc.lower_bound(_date);
	if (it == this->_btc.end()) {
		it--;
		std::cout << std::setprecision(2) << date << " => " << std::setprecision(2) << floatToString(_value) << " = " << floatToString(_value * (*it).second) << std::endl;
		return;
	}
	if (it == this->_btc.begin()) {
		std::cerr << "cannot find any closer data" << std::endl;
		return;
	}
	if ((*it).first != _date)
		it--;
	std::cout << std::setprecision(2) << date << " => " << std::setprecision(2) << floatToString(_value) << " = " << floatToString(_value * (*it).second) << std::endl;
}

void BitcoinExchange::run(const char *str) {
	std::ifstream file(str);
	std::string line;
	int year;
	int month;
	int day;
	float value;
	char extra;

	if (!file.is_open())
		throw(std::string) "could not open a file.";
	std::getline(file, line);
	if (line != "date | value")
		throw (std::string) line;
	while (std::getline(file, line)) {
		if (line.length() < 14 || sscanf((line.c_str()), "%d-%d-%d | %f%c", &year, &month, &day, &value, &extra) != 4)
			std::cout << "Error: bad input => " << line << std::endl;
		else {
			if (std::isspace(line[13]) || line[11] != '|' || line[line.length() - 1] == '.') {
				std::cout << "Error: bad input => " << line << std::endl;
				continue;
			}
			try {
				isDateValid(year, month, day);
				isValueValid(value);
				printResult(line.substr(0, 10));
			}
			catch (std::string error) {
				std::cout << "Error: " << error << std::endl;
			}
		}
	}
}
