#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

class ElementNotFound : public std::exception {
    public :
        const char *what() const throw() {
            return "element not found";
        }
};

template<typename T>
typename T::iterator easyfind(T& arg1, int arg2) {
    typename T::iterator iter = std::find(arg1.begin(), arg1.end(), arg2);
    if (iter == arg1.end())
        throw ElementNotFound();
    return iter;
}
