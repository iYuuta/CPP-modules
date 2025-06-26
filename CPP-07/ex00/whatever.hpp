#pragma once

template<typename arg1>
void swap(arg1& a, arg1& b) {
    arg1 tmp = a;
    a = b;
    b = tmp;
}

template<typename arg1>
arg1 min(arg1& a, arg1& b) {
    if (a < b)
        return a;
    return b;
}

template<typename arg1>
arg1 max(arg1& a, arg1& b) {
    if (a > b)
        return a;
    return b;
}