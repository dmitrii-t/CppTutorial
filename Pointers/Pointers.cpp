/* Pointers.cpp 
 * Exercising pointers
 */
#include <iostream>

int main()
{
    // definitions on pointers and ordinary variables can be mixed the following is the same as
    // long *pnumber; // Declaration of variable of type pointer to long
    // long number {99}; // Declaration and initialization of long variable
    long *pnumber, number{99};

    // using reference operator to assign the address of number to pnumber
    pnumber = &number;

    std::cout << "number: " << number << '\n';
    std::cout << "pnumber: " << pnumber << '\n';

    // using indirection operator to dereference pnumber to access the value
    std::cout << "*pnumber: " << *pnumber << '\n';
    std::cout << '\n';

    // initializing pointer
    int integer{};
    int* pinteger{&integer};

    std::cout << "integer: " << integer << '\n';
    std::cout << "*pinteger: " << *pinteger << '\n';


    // null pointers
    int* pnull{nullptr}; // 0 and NULL macro also work

    // nullptr can be implicitly converted to type bool
    if (!pnull)
    {
        std::cout << "pnull is null" << '\n';
    }
    std::cout << '\n';

    // there can be definitions of constant pointers to constant objects
    const char* const pstr[] = {
        "Robert Redford",
        "Hopalong Cassidy",
        "Lassie",
        "Slim Pickens",
        "Boris Karloff",
        "Oliver Hardy"
    };


    int data[3] = {1, 2, 3};
    
    // initialize pointer with the array address; not &data, but data
    int* pdata{data}; 
    std::cout << "data[0]: " << *pdata << '\n';

    // initialize pointer with the address of the second element
    pdata = &data[1]; 
    std::cout << "data[1]: " << *pdata << '\n';

    // you can apply pointer arithmetic to access the elements, this wil increase the pointer on 1*sizeof(int)
    pdata += 1;
    std::cout << "data[2]: " << *pdata << '\n';

    // but the following will increase the value of the pointer
    *pdata += 1;
    std::cout << "data[2]: " << *pdata << '\n';
    
    std::cout << '\n';
    return 0;
}
