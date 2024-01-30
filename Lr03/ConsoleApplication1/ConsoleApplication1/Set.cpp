#ifndef SET_CPP
#define SET_CPP

#include "Set.h"

template <class T>
Set<T>::Set() {}

template <class T>
Set<T>::~Set() {}

template <class T>
void Set<T>::insert(const T& value) {
    if (!contains(value)) {
        elements.push_back(value);
        std::sort(elements.begin(), elements.end());
    }
};

template <class T>
bool Set<T>::contains(const T& value) const {
    return std::binary_search(elements.begin(), elements.end(), value);
}

template <class T>
void Set<T>::print() const {
    for (const T& element : elements) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

#endif  // SET_CPP