#include "Array.h"

template<typename T>
Array<T>::Array() : ptr(NULL), len(0) {}

template<typename T>
Array<T>::Array(unsigned int n) {
    if (n)
    {
        this->ptr = new T[n]();
        this->len = n;
    }
    else
    {
        this->ptr = NULL;
        this->len = 0;
    }
}

template<typename T>
Array<T>::Array(const Array& obj) {
    
    this->len = obj.len;
    
    if (this->len)
    {
        this->ptr = new T[this->len]();
        for (size_t i = 0; i < obj.len; i++)
            this->ptr[i] = obj.ptr[i];
    }
    else
        this->ptr = NULL;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& obj) {
    if (this == &obj)
        return *this;
 
    delete[] this->ptr;
    
    this->ptr = NULL;
    this->len = obj.len;

    if (this->len)
    {
        this->ptr = new T[this->len]();
        for (size_t i = 0; i < obj.len; i++)
            this->ptr[i] = obj.ptr[i];
    }
    
    return *this;
}

template<typename T>
Array<T>::~Array() {
    delete[] this->ptr;
}

template<typename T>
size_t Array<T>::size() const { return this->len; }

template<typename T>
T& Array<T>::operator[](int index) {
    if (index < 0 || index >= static_cast<int>(this->len))
        throw std::out_of_range("Index is out of range");
    return this->ptr[index];
}

template<typename T>
const T& Array<T>::operator[](int index) const {
    if (index < 0 || index >= static_cast<int>(this->len))
        throw std::out_of_range("Index is out of range");
    return this->ptr[index];
}