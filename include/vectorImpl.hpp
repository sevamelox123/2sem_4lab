#pragma once
#include <initializer_list>
#include <iostream>

template <typename T>
class TetoVector
{
private:
    T *_data = nullptr;
    std::size_t _size = 0;
    std::size_t _capacity = 0;

public:
    class Iterator
    {
    private:
        T *ptr_ = nullptr;

    public:
        explicit Iterator(T *ptr);
        Iterator operator++();
        Iterator operator++(int);
        Iterator operator--();
        Iterator operator--(int);
        Iterator operator+(std::size_t n) const;
        Iterator operator-(std::size_t n) const;
        bool operator==(const Iterator& obj) const;
        bool operator!=(const Iterator& obj) const;
        bool operator>(const Iterator& obj) const;
        bool operator<(const Iterator& obj) const;
        bool operator<=(const Iterator& obj) const;
        bool operator>=(const Iterator& obj) const;
        T operator*();

        
    };

    TetoVector() = default;
    explicit TetoVector(std::size_t size);
    TetoVector(std::size_t size, const T &value);
    TetoVector(const TetoVector &obj);
    TetoVector(TetoVector &&obj) noexcept;
    TetoVector(std::initializer_list<T> init);
    ~TetoVector();

    TetoVector& operator=(const TetoVector& obj);
    TetoVector& operator=(TetoVector&& obj) noexcept;
    TetoVector& operator=(std::initializer_list<T> init);

    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;
    T& at(std::size_t index);
    const T& at(std::size_t index) const;
    std::size_t size() const;
    std::size_t capacity() const;
    bool empty() const;

    void reserve(std::size_t new_capacity);
    void resize(size_t new_size, const T& value);
    void push_back(const T& value);
    void push_back(T&& value);
    void pop_back();
    void clear();


    bool operator==(const TetoVector& other_vector) const;
    bool operator!=(const TetoVector& other_vector) const;
    bool operator<(const TetoVector& other_vector) const;
    bool operator<=(const TetoVector& other_vector) const;
    bool operator>(const TetoVector& other_vector) const;
    bool operator>=(const TetoVector& other_vector) const;

    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const TetoVector<U>& t_vec);


    // virtual Iterator insert(Iterator pos, const T& value);
    // virtual Iterator begin();


    Iterator end();
    Iterator begin();

    Iterator insert(Iterator pos, const T& value);
    Iterator insert(Iterator pos, T&& value);
    Iterator erase(Iterator pos);
    Iterator erase(Iterator first, Iterator last);
};

template <typename T>
TetoVector<T>::TetoVector(std::size_t size) : _size{size}, _capacity{size}
{

    _data = new T[size];
    for (std::size_t i = 0; i < size; i++)
    {
        _data[i] = T();
    }
}

template <typename T>
TetoVector<T>::TetoVector(std::size_t size, const T &value) : _size(size), _capacity{size}
{
    _data = new T[size];
    for (std::size_t i = 0; i < size; i++)
    {
        _data[i] = value;
    }
}

template <typename T>
TetoVector<T>::~TetoVector()
{
    delete[] _data;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const TetoVector<T>& t_vec)
{
    os << "[";
    for(std::size_t i = 0; i< t_vec._size; i++)
    {
        if(i!=0) os << ", ";
        os << t_vec[i];
    }
    os << "]";
    return os;

}

template<typename T>
TetoVector<T>::Iterator::Iterator(T *ptr) : ptr_(ptr) {

}

template <typename T>
typename TetoVector<T>::Iterator TetoVector<T>::begin() {
    return TetoVector<T>::Iterator(TetoVector<T>::_data);
}

template <typename T>
typename TetoVector<T>::Iterator TetoVector<T>::end()
{
    return TetoVector<T>::Iterator(TetoVector<T>::_data + TetoVector<T>::_size);
}

template<typename T>
T TetoVector<T>::Iterator::operator*() {
    if (ptr_ == nullptr) return 0;
    return *ptr_;
    // return 5;
}


template <typename T>
void TetoVector<T>::push_back(const T &value)
{
    if (_size >= _capacity)
    {
        reserve(_capacity == 0 ? 1 : _capacity * 2);
    }

    _data[_size++] = value;
}

template <typename T>
void TetoVector<T>::push_back(T &&value)
{
    if (_size >= _capacity)
    {
        reserve(_capacity == 0 ? 1 : _capacity * 2);
    }
    _data[_size++] = std::move(value);
}



template <typename T>
void TetoVector<T>::pop_back()
{
    if (_size > 0)
        --_size;
}

template <typename T>
inline void TetoVector<T>::reserve(std::size_t new_capacity)
{
    if (new_capacity > _capacity)
    {
        T *new_data = new T[new_capacity];
        for (std::size_t i = 0; i < _size; i++)
        {
            new_data[i] = _data[i];
        }
        delete[] _data;
        _data = new_data;
        _capacity = new_capacity;
    }
}

template <typename T>
TetoVector<T>::TetoVector(const TetoVector &obj) : _size{obj._size}, _capacity{obj._capacity}
{
    _data = new T[_capacity];
    for (std::size_t i = 0; i < _size; i++)
    {
        _data[i] = obj._data[i];
    }
}

template <typename T>
TetoVector<T>::TetoVector(TetoVector &&obj) noexcept : TetoVector<T>::TetoVector(obj._data, obj._size, obj._capacity)
{
}

template <typename T>
TetoVector<T>::TetoVector(std::initializer_list<T> init) : _size{init.size()}, _capacity{init.size()}
{
    _data = new T[_capacity];
    std::size_t i = 0;
    for (const T &item : init)
    {
        _data[i++] = item;
    }
}

template <typename T>
TetoVector<T> &TetoVector<T>::operator=(const TetoVector &obj)
{
    if (this != &obj)
    {
        delete[] _data;
        _size = obj._size;
        _capacity = obj._capacity;
        _data = new T(_capacity);
        for (std::size_t i = 0; i < _size; i++)
        {
            _data[i] = obj._data[i];
        }
    }
    return *this;
}

template <typename T>
TetoVector<T> &TetoVector<T>::operator=(TetoVector &&obj) noexcept
{
    if (this != &obj)
    {
        delete[] _data;
        _data = obj._data;
        _size = obj._size;
        _capacity = obj._capacity;
        obj._data = nullptr;
        obj._size = 0;
        obj._capacity = 0;
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
    for (const T &item : init)
    {
        _data[i++] = item;
    }
    return *this;
}

template <typename T>
T &TetoVector<T>::operator[](std::size_t index)
{
    return _data[index];
}

template <typename T>
const T &TetoVector<T>::operator[](std::size_t index) const
{
    return _data[index];
}

template <typename T>
T &TetoVector<T>::at(std::size_t index)
{
    if (index >= _size)
    {
        throw std::runtime_error("Out of range!");
    }
    return _data[index];
}

template <typename T>
const T &TetoVector<T>::at(std::size_t index) const
{
    if (index >= _size)
    {
        throw std::runtime_error("Out of range!");
    }
    return _data[index];
}

template <typename T>
std::size_t TetoVector<T>::size() const
{
    return _size;
}

template <typename T>
std::size_t TetoVector<T>::capacity() const
{
    return _capacity;
}

template <typename T>
bool TetoVector<T>::empty() const
{
    return _size == 0;
}

template <typename T>
typename TetoVector<T>::Iterator TetoVector<T>::Iterator::operator++()
{
    ++ptr_;
    return *this;
}

template <typename T>
typename TetoVector<T>::Iterator TetoVector<T>::Iterator::operator--()
{
    --ptr_;
    return *this;
}

template <typename T>
typename TetoVector<T>::Iterator TetoVector<T>::Iterator::operator++(int)
{
    Iterator temp = *this;
    ++ptr_;
    return temp;
}

template <typename T>
typename TetoVector<T>::Iterator TetoVector<T>::Iterator::operator--(int)
{
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
bool TetoVector<T>::Iterator::operator==(const Iterator &obj) const
{
    return ptr_ == obj.ptr_;
}

template <typename T>
bool TetoVector<T>::Iterator::operator!=(const Iterator &obj) const
{
    return ptr_ != obj.ptr_;
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
typename TetoVector<T>::Iterator TetoVector<T>::insert(
    typename TetoVector<T>::Iterator pos,
    const T& value
)
{
    std::size_t index = pos - begin();
    if (_size >= _capacity)
    {
        reserve(_capacity == 0 ? 1 : _capacity * 2);
    }
    for (std::size_t i = _size; i > index; --i)
    {
        _data[i] = _data[i - 1];
    }
    _data[index] = value;
    ++_size;
    return TetoVector<T>::Iterator(_data + index);
}

template <typename T>
typename TetoVector<T>::Iterator TetoVector<T>::insert(typename TetoVector<T>::Iterator pos, T &&value)
{
    std::size_t index = pos - begin();
    if (_size >= _capacity)
    {
        reserve(_capacity == 0 ? 1 : _capacity * 2);
    }
    for (std::size_t i = _size; i > index; --i)
    {
        _data[i] = std::move(_data[i - 1]);
    }
    _data[index] = std::move(value);
    ++_size;
    return TetoVector<T>::Iterator(_data + index);
}

template <typename T>
typename TetoVector<T>::Iterator  TetoVector<T>::erase(typename TetoVector<T>::Iterator pos)
{
    size_t index = pos - begin();
    for (size_t i = index; i < _size - 1; ++i)
    {
        _data[i] = std::move(_data[i + 1]);
    }
    --_size;
    return TetoVector<T>::Iterator(_data + index);
}

template <typename T>
typename TetoVector<T>::Iterator TetoVector<T>::erase(typename TetoVector<T>::Iterator first, typename TetoVector<T>::Iterator last)
{
    size_t first_index = first - begin();
    size_t last_index = last - begin();
    size_t count = last_index - first_index;

    for (size_t i = first_index; i < _size - count; ++i) {
        _data[i] = std::move(_data[i + count]);
    }
    _size -= count;
    return Iterator(_data + first_index);
}

template <typename T>
inline void TetoVector<T>::resize(size_t new_size, const T &value)
{
    if (new_size > _capacity)
    {
        reserve(new_size);
    }
    if (new_size > _size)
    {
        for (std::size_t i = _size; i < new_size; ++i)
        {
            _data[i] = value;
        }
    }
    _size = new_size;
}

template <typename T>
void TetoVector<T>::clear()
{
    _data = nullptr;
    _size = 0;
    _capacity = 0;
}

template <typename T>
bool TetoVector<T>::operator==(const TetoVector &other_vector) const
{
    if(_size != other_vector._size) return false;
    for(std::size_t i = 0; i < _size; i++)
    {
        if(_data[i] != other_vector._data[i]) return false;
    }
    return true;
}

template <typename T>
bool TetoVector<T>::operator!=(const TetoVector &other_vector) const
{
    return !(*this == other_vector);
}

template <typename T>
bool TetoVector<T>::operator<(const TetoVector &other_vector) const
{
    std::size_t min_size = std::min(_size, other_vector._size);
    for (std::size_t i = 0; i < min_size; ++i) {
        if (_data[i] < other_vector._data[i]) return true;
        if (_data[i] > other_vector._data[i]) return false;
    }
    return _size < other_vector._size;
}

template <typename T>
bool TetoVector<T>::operator<=(const TetoVector &other_vector) const
{
    return !(other_vector < *this);
}

template <typename T>
bool TetoVector<T>::operator>(const TetoVector &other_vector) const
{
    return other_vector < *this;
}

template <typename T>
bool TetoVector<T>::operator>=(const TetoVector &other_vector) const
{
    return other_vector < *this;
}