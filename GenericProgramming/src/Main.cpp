#include <iostream>

#include "Average.h"
#include "Mapping.h"
#include "Max.h"
#include "Product.h"

int main() {
    TestMax();
    TestProduct();
    TestAverage();
    TestMapping();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
