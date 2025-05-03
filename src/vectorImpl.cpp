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
TetoVector<T> &TetoVector<T>::operator=(const TetoVector &obj)
{
    if(this != &obj)
    {
        delete[] _data;
        _size = obj._size;
        _capacity = obj._capacity;
        _data = new T(_capacity);
        for(std::size_t = 0; i < _size; i++)
        {
            _data[i] = obj._data[i];
        }
    }
    return *this;

}

template <typename T>
TetoVector<T> &TetoVector<T>::operator=(TetoVector &&obj) noexcept
{
    if (this != &obj) {
        delete[] data_;
        data_ = obj.data_;
        size_ = obj.size_;
        capacity_ = obj.capacity_;
        obj.data_ = nullptr;
        obj.size_ = 0;
        obj.capacity_ = 0;
    }
    return *this;
}

template <typename T>
TetoVector<T> &TetoVector<T>::operator=(std::initializer_list<T> init)
{
    delete[] _data;
    _size = _capacity = init.size();
    _data = new T(_capacity);
    std::size_t i = 0;
    for (const T& item : init) {
            data_[i++] = item;
    }
    return *this;
}

template <typename T>
T &TetoVector<T>::operator[](std::size_t index)
{
    return _data[index];
}

template <typename T>
T &TetoVector<T>::at(std::size_t index)
{
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

template <typename T>
std::size_t TetoVector<T>::size() const
{
    return _size;
}

template <typename T>
std::size_t TetoVector<T>::capacity() const
{
    return capacity;
}

template <typename T>
bool TetoVector<T>::empty() const
{
    return _size == 0;
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

template <typename T>
typename TetoVector<T>::Iterator TetoVector<T>::Iterator::operator+(std::size_t n) const
{
    return Iterator(ptr_ + n);
}

template <typename T>
typename TetoVector<T>::Iterator TetoVector<T>::Iterator::operator-(std::size_t n) const
{
    return Iterator(ptr_ - n);
}

template <typename T>
bool TetoVector<T>::Iterator::operator==(const Iterator& obj) const {
    return ptr_ == obj.ptr_;
}

template <typename T>
bool TetoVector<T>::Iterator::operator!=(const Iterator &obj) const
{
    return ptr_ !=obj.ptr_;
}

template <typename T>
bool TetoVector<T>::Iterator::operator>(const Iterator &obj) const
{
    return ptr_ > obj.ptr_;
}

template <typename T>
bool TetoVector<T>::Iterator::operator<(const Iterator &obj) const
{
    return ptr_ < obj.ptr_;
}

template <typename T>
bool TetoVector<T>::Iterator::operator<=(const Iterator &obj) const
{
    return ptr_ <= obj.ptr_;
}

template <typename T>
bool TetoVector<T>::Iterator::operator>=(const Iterator &obj) const
{
    return ptr_ >= obj.ptr_;
}

template <typename T>
typename TetoVector<T>::Iterator TetoVector<T>::Iterator::begin()
{
    return Iterator(_data);
}

template <typename T>
typename TetoVector<T>::Iterator TetoVector<T>::Iterator::end()
{
    return Iterator(_data + _size);
}
