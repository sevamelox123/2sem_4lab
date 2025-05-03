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
    T& at(std::size_t index);
    std::size_t size() const;
    std::size_t capacity() const;
    bool empty() const;


    class Iterator
    {
    private:
        T *ptr_;

    public:
        explicit Iterator(T *ptr) : ptr_(ptr) {}
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

        Iterator begin();
        Iterator end();
        
    };
};
