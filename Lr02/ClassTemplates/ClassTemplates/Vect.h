#ifndef VECT_H
#define VECT_H

#include <iostream>
#include <algorithm>

template <typename T>
class Vect {
public:
    Vect();
    ~Vect();
    void push_back(const T& element);
    void remove(int index);
    int find(const T& element) const;
    int size() const;
    void print() const;
    /*
    void sortAscending() {
        std::sort(data, data + count);
    }*/
    void sort() {
        std::sort(data, data + count);
    }

private:
    T* data;
    int capacity;
    int count;
    void resize(int newCapacity);
};

template <typename T>
Vect<T>::Vect() : capacity(16), count(0), data(new T[capacity]) {}

template <typename T>
Vect<T>::~Vect() {
    delete[] data;
}

template <typename T>
void Vect<T>::push_back(const T& element) {
    if (count == capacity) {
        resize(capacity * 2);
    }
    data[count] = element;
    count++;
}

template <typename T>
void Vect<T>::remove(int index) {
    if (index < 0 || index >= count) {
        return;
    }
    for (int i = index; i < count - 1; i++) {
        data[i] = data[i + 1];
    }
    count--;
    if (capacity / 2 >= 16 && count < capacity / 2) {
        resize(capacity / 2);
    }
}

template <typename T>
int Vect<T>::find(const T& element) const {
    for (int i = 0; i < count; i++) {
        if (data[i] == element) {
            return i;
        }
    }
    return -1;
}

template <typename T>
int Vect<T>::size() const {
    return count;
}

template <typename T>
void Vect<T>::print() const {
    for (int i = 0; i < count; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void Vect<T>::resize(int newCapacity) {
    T* newData = new T[newCapacity];
    for (int i = 0; i < count; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

#endif // VECT_H