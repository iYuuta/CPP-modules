#pragma once

template<typename arg1, typename arg2, typename arg3>
void iter(arg1* add, arg2 len, arg3 func) {
    for (int i = 0; i < len; i++)
        func(add[i]);
}