#ifndef VECT_H
#define VECT_H

#include <iostream>
#include <algorithm>
#include <stdexcept>

template <class T>
class Vect {
public:
    Vect();
    Vect(const Vect& other);
    ~Vect();
    void push_back(const T& value);
    T& operator[](int index) const;
    T* begin() const { return data; }
    T* end() const { return data + length; }
    int size() const;
    void clear();

private:
    T* data;
    int capacity;
    int length;
};

#include "Vect.cpp"

#endif  // VECT_H