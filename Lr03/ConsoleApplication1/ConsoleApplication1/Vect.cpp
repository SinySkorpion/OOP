#ifndef VECT_CPP
#define VECT_CPP

#include "Vect.h"

template <class T>
Vect<T>::Vect() : data(nullptr), capacity(0), length(0) {}

template <class T>
Vect<T>::Vect(const Vect<T>& other) : data(nullptr), capacity(0), length(0) {
    capacity = other.capacity;
    length = other.length;
    data = new T[capacity];
    std::copy(other.data, other.data + length, data);
}

template <class T>
Vect<T>::~Vect() {
    delete[] data;
}

template <class T>
void Vect<T>::push_back(const T& value) {
    if (length == capacity) {
        int newCapacity = std::max(1, 2 * capacity);
        T* newData = new T[newCapacity];
        std::copy(data, data + length, newData);
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
    data[length++] = value;
}

template <class T>
T& Vect<T>::operator[](int index) const {
    if (index < 0 || index >= length) {
        throw std::out_of_range("Индекс вне диапазона");
    }
    return data[index];
}

template <class T>
int Vect<T>::size() const {
    return length;
}

template <class T>
void Vect<T>::clear() {
    delete[] data;
    data = nullptr;
    capacity = 0;
    length = 0;
}

#endif  // VECT_CPP