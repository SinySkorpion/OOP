#include "Set.h"

int main() {
    Set<int> set;

    set.add(5);
    set.add(2);
    set.add(7);
    set.add(2);
    set.add(9);

    set.print();

    return 0;
}