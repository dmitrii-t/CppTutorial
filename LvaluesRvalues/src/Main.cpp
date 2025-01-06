/*
 * LvaluesRvalues Example
 *
 *                              expression
 *              ↓------------------|----------------↓
 *         glvalue (generalized)                  rvalue
 *   ↓----------|----------------↓    ↓-------------|----------↓
 * lvalue                        xvalue                      prvalue
 *
 * lvalue (left/locator value):
 * - Has an address that can be accessed
 * - Expressions whose evaluation determines the identity of objects or functions
 * - Examples: variables, array elements, struct members, references
 * - Can appear on left side of assignment
 *
 * rvalue (right value):
 * - Cannot appear on the left side of an assignment
 * - Includes both xvalues and prvalues
 * - Temporary objects or values that can be moved from
 * - Examples: temporaries, function returns, literals
 *
 * prvalue (pure rvalue):
 * - Does not have an address that is accessible directly
 * - Temporary expressions used to initialize objects or compute values
 * - Examples: literals (42, true), results of most operators (+, -, *),
 *   function calls returning non-references
 * - Cannot be assigned to
 *
 * xvalue (expiring value):
 * - Represents resources that can be reused
 * - Result of certain kinds of expressions that designate object resources
 * - Examples: result of std::move(), array subscript of array rvalue
 * - Can be moved from but still has identity
 *
 * Note:
 * - glvalue = generalized lvalue (lvalue + xvalue)
 * - rvalue = xvalue + prvalue
 * - Modern C++ move semantics introduced xvalues as a new category
 */

#include <iostream>

using std::cout;
using std::string;

/* The class A below follows the Rule of Five
 *
 * Rule of Five
 * If you have to write one of the functions listed below then you should consider
 * implementing all of them with a proper resource management policy in place
 *
 * The destructor: Responsible for freeing the resource once the object it belongs to
 * goes out of scope.
 *
 * The assignment operator: The default assignment operation performs a member-wise
 * shallow copy, which does not copy the content behind the resource handle. If a deep
 * copy is needed, it has be implemented by the programmer.
 *
 * The copy constructor: As with the assignment operator, the default copy constructor
 * performs a shallow copy of the data members. If something else is needed, the
 * programmer has to implement it accordingly.
 *
 * The move constructor: Because copying objects can be an expensive operation which
 * involves creating, copying and destroying temporary objects, rvalue references are
 * used to bind to an rvalue. Using this mechanism, the move constructor transfers the
 * ownership of a resource from a (temporary) rvalue object to a permanent lvalue
 * object.
 *
 * The move assignment operator: With this operator, ownership of a resource can be
 * transferred from one object to another. The internal behavior is very similar to the
 * move constructor.
 *
 */
class A {
public:
    A() {
        instancecnt_++;
        numberptr_ = new int(1);
        printf("default constr a(%d)\n", instancecnt_);
    }

    ~A() {
        printf("destroying a(%d)\n", instancecnt_);
        delete numberptr_;
        instancecnt_--;
    }

    A(const A& source) {  // the copy constructor creates a deep copy
        instancecnt_++;
        numberptr_ = new int(*source.numberptr_);  // creating a deep copy of
                                                   // the source.numberptr_

        printf("copy constr a(%d)\n", instancecnt_);
    }

    A& operator=(const A& source) {  // the copy assignment operator creates a deep copy
        if (this == &source) {       // self-assignment protection boilerplate
            return *this;
        }
        delete numberptr_;
        numberptr_ = new int(
            *source.numberptr_);  // creating a deep copy of the source.numberptr_
        printf("lvalue assign operator a(%d)\n", instancecnt_);
        return *this;
    }

    A(A&& source) {  // the move constructor transfers ownership of the internal
                     // resource
        instancecnt_++;
        numberptr_ = source.numberptr_;  // transferring ownership over numberptr_
        source.numberptr_ = nullptr;     // to a copy

        printf("move constr a(%d)\n", instancecnt_);
    }

    A& operator=(A&& source) {  // the move assign operator transfers ownership over
                                // internal resource
        if (this == &source) {  // self-assignment protection boilerplate
            return *this;
        }
        delete numberptr_;
        numberptr_ = source.numberptr_;  // transferring ownership over numberptr_
        source.numberptr_ = nullptr;     // to a copy

        printf("rvalue assign operator a(%d)\n", instancecnt_);
        return *this;
    }

    static int instancecnt_;
    int*       numberptr_;
};

int A::instancecnt_ = 0;

void func(int& lvalue) {
    cout << "lvalue=" << lvalue << '\n';
}
void func(int&& rvalue) {
    cout << "rvalue=" << rvalue << '\n';
}

int main() {
    cout << "LvaluesRvalues example" << '\n';

    //  Lvalue (locator value) refers to an object that occupies a specific
    //  location in memory (i.e., it has an identifiable address).
    [[maybe_unused]] int x = 10;  // 'x' is an lvalue
    x                      = 20;  // 'x' is an lvalue again
    [[maybe_unused]] int* p =
        &x;  // 'p' is an lvalue because it's a pointer variable with a memory
             // location, '&x' is an rvalue as it's temporary value produced by the
             // address operator (&)

    //  Rvalue (right value) is a temporary value that does not persist beyond the
    //  expression that uses it. Rvalues are typically literals, temporary
    //  objects, or the results of expressions.
    int                   y = 10;  // '10' is a rvalue as literal can only appear on the
    [[maybe_unused]] int  z = x + y;  // 'x + y' is an rvalue
    [[maybe_unused]] int* q =
        &x;  // '&x' is an rvalue as it's temporary value produced by the
    // address operator (&)

    // int* q = &(x + y); // Error! 'x + y' is an rvalue and doesn't have a memory
    // address
    [[maybe_unused]] int&& r =
        x + y;  // but this is rvalue reference, find details below

    // Examples
    // lvalue reference
    int  i = 1;
    int& j = i;
    ++i;
    ++j;
    std::cout << "i = " << i << ", j = " << j << '\n';

    cout << "-- rvalue reference example" << "\n";
    string&& rvalue_ref  = static_cast<string>("g'") + static_cast<string>("day");
    string&  lvalue_ref  = rvalue_ref;
    rvalue_ref          += " ";
    rvalue_ref          += "Australia";
    printf(
        "lvalue_ref[%p]=%s\n"
        "rvalue_ref[%p]=%s\n",
        &lvalue_ref, lvalue_ref.c_str(), &rvalue_ref, rvalue_ref.c_str());

    cout << "-- function overloading with rvalue reference" << "\n";
    int a = 5;

    func(a);                   // Calls lvalue reference function
    func(5);                   // Calls rvalue reference function

    cout << "-- move semantics" << "\n";
    A obj1;                    // calls default constructor A::A()

    A obj2 = obj1;             // calls copy constructor A::A(const A&) as
                               // obj2 was not exist before

    obj2 = obj1;               // calls assignment operator A::operator=(const A&)
                               // existed before as obj2 never

    A obj3 = std::move(obj1);  // calls move constructor A::A(const A&&)

    return 0;
}
