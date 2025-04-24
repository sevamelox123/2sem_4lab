#include "vectorImpl.hpp"

template <typename T>
TetoVector<T>::TetoVector(std::size_t size) : _size{size}, _capacity{size}{

    _data = new T[size];
    for(std::size_t i = 0; i<size;i++)
    {
        _data[i] = T();
    }
}

template <typename T>
TetoVector<T>::TetoVector(std::size_t size, const T &value) : _size(size), _capacity{size}{
    _data = new T[size];
    for(std::size_t i = 0; i<size; i++)
    {
        _data[i] = value;
    }
}

template <typename T>
TetoVector<T>::TetoVector(const TetoVector &obj) : _size{obj._size} , _capacity{obj._capacity}{
    _data = new T[_capacity];
    for(std::size_t i = 0; i<_size; i++)
    {
        _data[i] = obj._data[i];
    }
}

template <typename T>
TetoVector<T>::TetoVector(TetoVector &&obj) noexcept : TetoVector<T>::TetoVector(obj._data, obj._size, obj._capacity){
}

template <typename T>
TetoVector<T>::TetoVector(std::initializer_list<T> init) : _size{init.size()}, _capacity{init.size()}{
    _data = new T[_capacity];
    std::size_t i = 0;
    for(const T& item : init)
    {
        _data[i++] = item;
    }
}

template <typename T>
TetoVector<T>::~TetoVector()
{
    delete[] _data;
}

template <typename T>
typename TetoVector<T>::Iterator TetoVector<T>::Iterator::operator++() {
    ++ptr_;
    return *this;
}

template <typename T>
typename TetoVector<T>::Iterator TetoVector<T>::Iterator::operator--() {
    --ptr_;
    return *this;
}

template <typename T>
typename TetoVector<T>::Iterator TetoVector<T>::Iterator::operator++(int) {
    Iterator temp = *this;
    ++ptr_;
    return temp;
}

template <typename T>
typename TetoVector<T>::Iterator TetoVector<T>::Iterator::operator--(int) {
    Iterator temp = *this;
    --ptr_;
    return temp;
}