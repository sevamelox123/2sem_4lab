#pragma once
#include <initializer_list>

template <typename T>
class TetoVector
{
private:
    T *_data = nullptr;
    std::size_t _size = 0;
    std::size_t _capacity = 0;

public:
    TetoVector() = default;
    TetoVector(std::size_t size);
    TetoVector(std::size_t size, const T& value);
    TetoVector(const TetoVector &obj);
    TetoVector(TetoVector &&obj) noexcept;
    TetoVector(std::initializer_list<T> init);
    ~TetoVector();

    class Iterator
    {
    private:
        T *ptr_;

    public:
        Iterator operator++();
        Iterator operator++(int);
        Iterator operator--();
        Iterator operator--(int);
    };
};
