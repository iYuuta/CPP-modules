#include "Span.hpp"

Span::Span() {};

Span::Span(unsigned int _size):size(_size), index(0){
    this->arr.reserve(_size);
}

Span::Span(const Span& copy){
    *this = copy;
}

Span::~Span() {};

Span& Span::operator=(const Span& copy) {
    if (this == &copy)
        return *this;
    this->size = copy.size;
    this->index = copy.index;
    this->arr.resize(size);
    for (unsigned int i = 0; i < size; i++)
        arr[i] = copy.arr[i];
    return *this;
}

void Span::addNumber(int num) {
    if (index == size)
        throw StorageIsFull();
    else {
        index++;
        arr.push_back(num);
    }
}

int Span::longestSpan() const {
    if (size < 2)
        throw NotEnoughElements();
    std::vector<int> sorted = arr;
    std::sort(sorted.begin(), sorted.end());
    return (*(sorted.end() - 1) - *sorted.begin());
}

int Span::shortestSpan() const {
    int span = -1;
    if (size < 2)
        throw NotEnoughElements();
    std::vector<int> sorted = arr;
    std::sort(sorted.begin(), sorted.end());
    for (unsigned int i = 1; i < size; i++) {
        if (span == -1 || sorted[i] - sorted[i - 1] < span)
            span = sorted[i] - sorted[i - 1];
    }
    return span;
}

void Span::fillStorage(const std::vector<int> &_arr) {
    if (arr.size() + std::distance(_arr.begin(), _arr.end()) > size)
        throw StorageIsFull();
    arr.insert(arr.end(), _arr.begin(), _arr.end());
}

const char *Span::StorageIsFull::what() const throw() {
    return "storage is full";
}

const char *Span::NotEnoughElements::what() const throw() {
    return "Not enough elements";
}