#include "Serializer.h"


Serializer::Serializer() {}

Serializer::Serializer(const Serializer& obj) {
    (void)obj;
}

Serializer& Serializer::operator=(const Serializer& obj) {
    (void)obj;
    return *this;
}

Serializer::~Serializer() {}


uintptr_t Serializer::serialize(const Data *ptr) {
    if (!ptr)
        return 0;
    return reinterpret_cast<uintptr_t>(ptr);    
}

Data* Serializer::deserialize(const uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

