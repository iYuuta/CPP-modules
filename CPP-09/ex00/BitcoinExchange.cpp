#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    std::string buff;
    std::ifstream infile;
    
    infile.open("data.csv");
    if (!infile.is_open())
        throw FailedToOpenFile();
    int index;
    std::getline(infile, buff);
    while (std::getline(infile, buff)) {
        index = buff.find(",");
        this->btc.insert(std::make_pair(get_date(buff, index), get_value(buff, index)));
    }
}

BitcoinExchange::~BitcoinExchange() {}

const char *BitcoinExchange::FailedToOpenFile::what() const throw (){
    return "could not open file.";
}

float get_value(std::string& str, int index) {
    std::string tmp = str.substr(index + 1, str.length() - index + 1);
    return atof(tmp.c_str());
}

unsigned long get_date(std::string& str, int index) {
    std::string tmp = str.substr(0, index - 1);
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '-'), tmp.end());
    unsigned long result = std::stoi(tmp);
    return result;
}

float BitcoinExchange::getvalue(unsigned long index) {
    std::map<unsigned long, float>::iterator it = btc.lower_bound(index);
    if (it != btc.end() && it->first == index)
        return it->second;
    if (it == btc.begin())
        return 0.0f;
    --it;
    return it->second;
}
