#pragma once

#include <string>
#include <exception>
#include <iostream>
#include <climits>

template<typename T>
class Array {
private:
    T* arr;
    unsigned int _size;
public:
    Array():arr(NULL), _size(0){};
    Array(int size) {
        if (size < 0)
            throw InvalidIndex();
        arr = new T[size];
        _size = size;
    }
    Array(const Array& copy) {
        this->_size = copy._size;
        this->arr = new T[this->_size];
        for (unsigned int i = 0; i < this->_size; i++)
            this->arr[i] = copy.arr[i];
    }
    Array& operator=(const Array& copy) {
        if (this == &copy)
            return *this;
        if (this->arr)
            delete this->arr;   
        this->arr = NULL;
        this->_size = copy._size;
        this->arr = new T[copy._size];
        for (unsigned int i = 0; i < _size; i++) {
            this->arr[i] = copy.arr[i];
        }
        return *this;
    }
    T& operator[](int i) const {
        if (i < 0 || i >= (int)_size)
            throw InvalidIndex();
        return arr[i];
    }
    ~Array() {
        if (arr)
            delete[] arr;
    };
    unsigned int size() const {
        return _size;
    };
    class InvalidIndex: public std::exception {
        public:
        const char *what() const throw() {
            return "Invalid index";
        }
    };
};

