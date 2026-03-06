#pragma once

#include "Data.h"
#include <iostream>
#include <stdint.h>

class Serializer
{
public:
    static uintptr_t serialize(const Data *ptr);
    static Data *deserialize(const uintptr_t raw);

private:
    Serializer();
    Serializer(const Serializer &obj);
    Serializer &operator=(const Serializer &obj);
    ~Serializer();
};
