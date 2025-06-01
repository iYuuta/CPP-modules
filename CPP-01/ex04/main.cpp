#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

int check_pattern(std::string pattern) {
    if (pattern.empty()) {
        std::cout << "empty pattern" << std::endl;
        return 1;
    }
    return 0;
}

int check_replacement(std::string replacement) {
    
    if (replacement.empty()) {
        std::cout << "empty replacement" << std::endl;
        return 1;
    }
    return 0;
}

int check_infile(std::string infile) {
    
    if (infile.empty()) {
        std::cout << "empty infile" << std::endl;
        return 1;
    }
    return 0;
}

void replace_line(std::string& string, const std::string pattern, const std::string replacement) {
    std::string result;

    for (size_t i = 0; i < string.length(); i++) {
        if (string.substr(i, pattern.length()) == pattern) {
            result += replacement;
            i += pattern.length() - 1;
        }
        else
            result += string[i];
    }
    string = result;
}


int main(int ac, char **av) {
    if (ac != 4) {
        std::cerr << "Invalid arguments" << std::endl;
        return 1;
    }
    if (check_infile(av[1]) || check_pattern(av[2]) || check_replacement(av[3]))
        return 1;
    std::fstream read_in(av[1]);
    if (!read_in.is_open()) {
        std::cerr << "Failed to open the infile" << std::endl;
        return 1;
    }
    std::ofstream read_out((std::string(av[1]) + ".replace").c_str());
    if (!read_out.is_open()) {
        std::cerr << "Failed to open the outfile" << std::endl;
        return 1;
    }
    std::string buffer;
    std::ostringstream tmpstream;
    tmpstream << read_in.rdbuf();
    buffer = tmpstream.str();
    replace_line(buffer, av[2], av[3]);
    read_out << buffer;
    read_in.close();
    read_out.close();
}
