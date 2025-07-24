#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	std::cout << std::fixed << std::setprecision(2);
	if (ac != 2) {
		std::cerr << "invalid arguments\n";
		return 1;
	}
	try {
		BitcoinExchange btc;
		btc.run(av[1]);
	}
	catch (std::string error) {
		std::cerr << "error: " << error << std::endl;
		return 1;
	}	
	return 0;
}
