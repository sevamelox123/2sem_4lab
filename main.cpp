#include <iostream>
#include "vectorImpl.hpp"

using namespace std;


int main() {
    // Тестирование конструкторов
    TetoVector<int> v1;
    // TetoVector<int> v2(5);
    TetoVector<int> v3(3, 42);
    // TetoVector<int> v4 = {1, 2, 3, 4, 5};
    // TetoVector<int> v5(v4);
    // TetoVector<int> v6(std::move(v5));

    std::cout << "Teto" << std::endl;

    // Тестирование методов
    v3.push_back(10);
    // v1.push_back(20);
    // v1.push_back(30);

    // std::cout << *(v3.end()) << std::endl;

    // v3.at(4) = 5;

    for (auto it = v3.begin();it != v3.end();it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << v3 << std::endl;

    // std::cout << "v1: " << v1 << std::endl;
    // std::cout << "v1 size: " << v1.size() << ", capacity: " << v1.capacity() << std::endl;

    // // Тестирование итераторов
    // std::cout << "v4 elements: ";
    // for (auto it = v4.begin(); it != v4.end(); ++it) {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;

    // // Тестирование операторов сравнения
    // Vector<int> a = {1, 2, 3};
    // Vector<int> b = {1, 2, 4};
    // std::cout << "a < b: " << (a < b) << std::endl;

    return 0;
}