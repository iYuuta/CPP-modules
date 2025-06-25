#pragma once

#include <string>
#include <iostream>
#include "Data.hpp"

typedef unsigned long int	uintptr_t;

class Serializer {
    private:
        Serializer();
        Serializer(const Serializer& copy);
    public:
        Serializer& operator=(const Serializer& copy);
        ~Serializer();
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};
