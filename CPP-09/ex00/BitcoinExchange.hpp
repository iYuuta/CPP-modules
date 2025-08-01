#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>
#include <iomanip>
#include <sstream>

class BitcoinExchange {
	private:
		std::map<unsigned long, double>	_btc;
		double							_value;
		unsigned long					_date;
		double 							getValue(std::string& str, int index);
		unsigned long					getDate(std::string& str, int index);
		void 							printResult(const std::string& line);
		const std::string				floatToString(float value);

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);

		void run(const char *str);
		void isDateValid(int year, int month, int day);
		void isValueValid(float value);
};
