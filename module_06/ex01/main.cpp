#include "Serializer.h"

int main()
{
    Data a;
    Data b;

    a.key = 'a';
    a.value = 10;
    a.next = &b;

    b.key = 'b';
    b.value = 20;
    b.next = NULL;

    Data* ptr = &a;

    std::cout << "Original pointer: " << ptr << std::endl;
    std::cout << "Key: " << ptr->key << " Value: " << ptr->value << std::endl;

    uintptr_t raw = Serializer::serialize(ptr);
    if (!raw)
    {
        std::cout << "Error: can't serialize the data" << std::endl;
        return 1;
    }
    std::cout << "Serialized value: " << raw << std::endl;

    Data* restored = Serializer::deserialize(raw);

    std::cout << "Restored pointer: " << restored << std::endl;
    std::cout << "Key: " << restored->key << " Value: " << restored->value << std::endl;

    if (restored->next)
    {
        std::cout << "Next node:\nKey: "
                  << restored->next->key 
                  << " Value: "
                  << restored->next->value << std::endl;
    }

    return 0;
}