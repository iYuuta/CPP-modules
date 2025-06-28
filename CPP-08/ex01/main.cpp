#include "Span.hpp"

int main() {
    int values[] = {0, 4, 12, 7, 9, 15, 76, 74, 118, 59};
    std::vector<int> arr(values, values + 10);
    Span sp1 = Span(5);
    Span sp2 = Span(10);
    try {
        sp1.addNumber(6);
        sp1.addNumber(3);
        sp1.addNumber(17);
        sp1.addNumber(9);
        sp1.addNumber(11);
    }
    catch (const std::exception& exc) {
        std::cout << "an error accured: " << exc.what() << std::endl;
    }
    try {
        sp2.fillStorage(arr);
    }
    catch (const std::exception& exc) {
        std::cout << "an error accured: " << exc.what() << std::endl;
    }
    std::cout << sp1.shortestSpan() << std::endl;
    std::cout << sp1.longestSpan() << std::endl;
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;
    return 0;
}
