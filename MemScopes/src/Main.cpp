/*
 * There are three main storage durations in C++: automatic, dynamic, and
 * static.
 *
 * Static storage duration means that the variable is allocated when the program
 * starts and is deallocated when the program ends. These variables retain their
 * values throughout the entire execution of the program.
 *
 * Automatic storage refers to the storage duration of variables that are
 * created and destroyed on the stack automatically. Variables with automatic
 * storage duration are typically declared as local variables within a block or
 * function.
 *
 * Dynamic storage in C++ refers to the allocation and deallocation of memory
 * during the program's execution. Unlike automatic storage (local variables)
 * and static storage (global and static variables), dynamic storage allows you
 * to allocate memory at runtime using operators like `new` and deallocate it
 * using `delete` (or malloc and free in C-style memory management).
 *
 */
#include <iostream>

int count{10};

void printStaticVar() {
  // Persists variable in the Static storage
  static int staticCount{0};

  // Print the current value of localVar
  std::cout << "Static count equals: " << staticCount << std::endl;

  // Increment localVar
  staticCount++;
}

int main() {
  int count{20};
  std::cout << "Inner count equals: " << count << std::endl;

  {
    // This hides the outer count variable. Valid code but BAD PRACTICE
    std::cout << "Entering a new scope" << std::endl;

    int count{30};

    std::cout << "Inner count equals: " << count << std::endl;
    std::cout << "Global count equals: " << ::count << std::endl;

    // Inner variable count gets destroyed when the block ends
  }

  /*
   * Prints out the following
   * Static count equals: 0
   * Static count equals: 1
   */
  printStaticVar();
  printStaticVar();

  /* Dynamic variable
   */
  int *dynamic_variable = new int{100};
  std::cout << "Dynamic variable equals: " << *dynamic_variable << std::endl;
  delete dynamic_variable;

  return 0;
}
