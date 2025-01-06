#pragma once

#include <iostream>

using std::cout;

void ExNoRaii() {
    double den[] = {1.0, 2.0, 3.0, 4.0, 5.0};

    for (size_t i = 0; i < std::size(den); ++i) {
        // allocate the resource on the heap
        double* en = new double(i);

        // use the resource
        cout << *en << "/" << den[i] << " = " << *en / den[i] << '\n';

        // deallocate the resource
        delete en;
    }
}