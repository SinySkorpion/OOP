#ifndef SET_H
#define SET_H

#include "Vect.h"

template <class T>
class Set {
public:
    Set();
    ~Set();
    void insert(const T& value);
    bool contains(const T& value) const;
    void print() const;  


private:
    Vect<T> elements;
};

#include "Set.cpp" 

#endif  // SET_H