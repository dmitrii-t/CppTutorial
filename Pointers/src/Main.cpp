/* Pointers.cpp
 * Exercising pointers
 */
#include <iostream>
#include <vector>

using namespace std;

void Increment(int *i) {
  // Dereference the pointer and increment the int being pointed to.
  (*i)++;
}

int *OutOfScopePointer() {
  int i = 100;
  int *pi = &i;
  cout << "OutOfScopePointer: &i=" << pi << '\n';
  return pi;
}

int main() {
  cout << "type <variables name>{value} - declaring and initializing a variable"
       << '\n';
  long number{99};
  cout << "long number{99}=" << number << '\n' << '\n';

  cout << "type& <variables name>{value} - declaring a reference" << '\n';
  long &rnumber{number};
  cout << "long& rnumber{number}=" << rnumber << '\n' << '\n';

  // initializing pointer
  cout << "type* <variable's name>{&value} - declaring a pointer" << '\n';
  long *pnumber{&number};
  cout << "long* pnumber{&number}=" << pnumber << '\n' << '\n';

  cout << "pnumber = &number - using overloaded reference operator & - to get "
          "the address of number to pnumber"
       << '\n';
  pnumber = &number;
  cout << "pnumber=" << pnumber << '\n' << '\n';

  cout << "*pnumber - using indirection operator to dereference pnumber to "
          "access the value"
       << '\n';
  cout << "*pnumber=" << *pnumber << '\n';
  cout << '\n';

  cout << "int* pnull{nullptr} - initializing a pointer with nullptr value; 0 "
          "and NULL macro also work"
       << '\n';
  int *pnull{nullptr};
  cout << "*pnull=" << pnull << " do NOT try to dereference *pnull" << '\n'
       << '\n';

  cout << "nullptr can be implicitly converted to type bool" << '\n';
  cout << "if (!pnull) { cout << \"pnull is null\" }" << '\n';
  if (!pnull) {
    cout << "pnull is null" << '\n';
  }
  cout << '\n';

  // there can be definitions of constant pointers to constant objects
  const char *const pstr[] = {"Robert Redford", "Hopalong Cassidy",
                              "Lassie",         "Slim Pickens",
                              "Boris Karloff",  "Oliver Hardy"};

  cout << "given array " << '\n';
  cout << "int data[3] = {1, 2, 3}" << '\n';
  int data[3] = {1, 2, 3};
  cout << '\n';

  cout << "array variable is not an actual pointer but decays into a pointer "
          "to the first element"
       << '\n';
  cout << "*data=" << *data << '\n';
  cout << "*(data + 1)=" << *(data + 1) << '\n';
  cout << "*(data + 2)=" << *(data + 2) << '\n';
  cout << '\n';

  cout << "initialize pointer with the array address; not &data, but data"
       << '\n';
  cout << "int* pdata{data};" << '\n';
  int *pdata{data};
  cout << "data[0]=" << *pdata << '\n';
  cout << '\n';

  cout << "initialize pointer with the address of the second element" << '\n';
  cout << "pdata = &data[1];" << '\n';
  pdata = &data[1];
  cout << "data[1]=" << *pdata << '\n';
  cout << '\n';

  cout << "you can apply pointer arithmetic to access the elements, this wil "
          "increase the pointer on 1*sizeof(int)"
       << '\n';
  cout << "pdata += 1" << '\n';
  pdata += 1;
  cout << "data[2]=" << *pdata << '\n';
  cout << '\n';

  cout << "but the following will increase the value the pointer points to"
       << '\n';
  cout << "*pdata += 1;" << '\n';
  *pdata += 1;
  cout << "data[2]=" << *pdata << '\n';
  cout << '\n';

  // Example with a vector
  vector<int> v{1, 2, 3};
  vector<int> *pv = &v;

  cout << "data=[ ";
  for (long i = 0; i < pv->size(); i++) {
    cout << pv->at(i) << ',';
  }
  cout << "]" << '\n';
  cout << '\n';

  // Example with pass-by-reference with a pointer
  int i = 0;
  cout << "i=" << i << '\n';
  cout << "Increment(&i)" << '\n';
  Increment(&i);
  cout << "i=" << i << '\n';
  cout << '\n';

  int *j = OutOfScopePointer();
  cout << "int* j = OutOfScopePointer(); j=" << j
       << " // *OutOfScopePointer() fails as pointer is out of scope" << '\n';
  cout << '\n';

  return 0;
}
