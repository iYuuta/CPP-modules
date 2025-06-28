#pragma once

#include <vector>
#include <iostream>
#include <exception>
#include <algorithm>

class Span {
    private:
        std::vector<int> arr;
        unsigned int size;
        unsigned int index;
        Span();
    public:
        Span(unsigned int size);
        ~Span();
        Span(const Span& copy);
        Span& operator=(const Span& copy);
        void addNumber(int num);
        int shortestSpan() const ;
        int longestSpan() const ;
        void fillStorage(const std::vector<int> &_arr);
        class StorageIsFull: public std::exception {
            public :
                const char *what() const throw();
        };
        class NotEnoughElements: public std::exception {
            public :
                const char *what() const throw();
        };
};
