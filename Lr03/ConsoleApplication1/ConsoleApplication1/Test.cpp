// Test.cpp
#include <cassert>
#include "Test.h"
#include "Set.h"

void testIntegerSet() {
    Set<int> intSet;
    intSet.insert(10);
    intSet.insert(20);
    assert(intSet.contains(10));
    assert(intSet.contains(20));
    assert(!intSet.contains(30));
}

void testDoubleSet() {
    Set<double> doubleSet;
    doubleSet.insert(1.1);
    doubleSet.insert(2.2);
    assert(doubleSet.contains(1.1));
    assert(doubleSet.contains(2.2));
    assert(!doubleSet.contains(3.3));
}

void testStringSet() {
    Set<std::string> stringSet;
    stringSet.insert("test");
    stringSet.insert("set");
    assert(stringSet.contains("test"));
    assert(stringSet.contains("set"));
    assert(!stringSet.contains("notInSet"));
}