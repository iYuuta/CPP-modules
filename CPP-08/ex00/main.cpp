#include "easyfind.hpp"

int main() {
    int values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> arr(values, values + 10);

    try {
        std::cout << *easyfind(arr, 5) << std::endl;
        std::cout << *easyfind(arr, 9) << std::endl;
        std::cout << *easyfind(arr, 51) << std::endl;
    }
    catch (const std::exception& exc) {
        std::cerr << "an error accured: " << exc.what() << std::endl;
    }
}
