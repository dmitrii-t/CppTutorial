#pragma once
#include <iostream>

void RunLambdas() {
    int id{0}; // defines an integer variable
    std::cout << "0. id on main \t\t\t&id=" << &id << '\n';
    
    // capture by reference immutable, pass nothing
    auto f0 = [&id]() {
        std::cout << "1. id ref capture in lambda f0 \t&id=" << &id << ' ';
        ++id;
    };
    f0();
    std::cout << "id val on main id=" << id << '\n';
    
    // capture by reference mutable, pass nothing
    auto f1 = [&id]()mutable {
        std::cout << "2. id ref capture in lambda f1 \t&id=" << &id << ' ';
        ++id;
    };
    f1();
    std::cout << "id val on main id=" << id << '\n';
    
    // capture by value mutable, pass nothing
    auto f2 = [id]() mutable {
        std::cout << "3. id val capture in lambda f2 \t&id=" << &id << ' ';
        ++id;
    };
    f2();
    std::cout << "id val on main id=" << id << '\n';

    // capture ALL by ref, pass nothing
    auto f3 = [&]() mutable {
        std::cout << "3. id ref capture in lambda f3 \t&id=" << &id << ' ';
        ++id;
    };
    f3();
    std::cout << "id val on main id=" << id << '\n';
    
    // capture nothing, pass a reference
    auto f4 = [](int& id) {
        std::cout << "4. id ref in lambda f4 \t\t&id=" << &id << ' ';
        ++id;
    };
    f4(id);
    std::cout << "id val on main id=" << id << '\n';

    // capture nothing, pass a copy
    auto f5 = [](int id) {
        std::cout << "5. id cpy in lambda f5 \t\t&id=" << &id << ' ';
        ++id;
    };
    f5(id);
    std::cout << "id val on main id=" << id << '\n';
}