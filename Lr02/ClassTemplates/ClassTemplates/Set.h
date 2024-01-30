#ifndef SET_H
#define SET_H

#include "Vect.h"

template <typename T>
class Set {
public:
    Set();
    ~Set();

    void add(const T& element);
    void remove(const T& element);
    bool contains(const T& element) const;
    int size() const;
    void print() const;

private:
    Vect<T> elements;
};

// ¬ключение реализации методов в заголовочный файл
template <typename T>
Set<T>::Set() {}

template <typename T>
Set<T>::~Set() {}

template <typename T>
void Set<T>::add(const T& element) {
    if (!contains(element)) {
        elements.push_back(element);
    }
}

template <typename T>
void Set<T>::remove(const T& element) {
    int index = elements.find(element);
    if (index != -1) {
        elements.remove(index);
    }
}

template <typename T>
bool Set<T>::contains(const T& element) const {
    return elements.find(element) != -1;
}

template <typename T>
int Set<T>::size() const {
    return elements.size();
}

template <typename T>
void Set<T>::print() const {
    Vect<T> tempElements = elements;
    tempElements.sort();
    tempElements.print();
}

#endif // SET_H