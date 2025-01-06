/*
 * The technique of wrapping a management class around a resource  is called
 * Resource Acquisition Is Initialization (RAII)
 *
 *  RAII can be used to protect a resource such as a file stream, a network connection
 * or a block of memory which need proper management.
 *
 *  Acquiring and releasing resources
 * A general resource usage pattern looks like the following.
 *
 * .-------------------.
 * | Obtain resource   |
 * '-------------------'
 *          ↓
 * .-------------------.
 * | Use resource      |
 * '-------------------'
 *          ↓
 * .-------------------.
 * | Release resource  |
 * '-------------------'
 *
 * The the main problem with pattern is that the resource cleanup may fail in several
 * ways
 * 1 if an exception occurs while the resource is in use, the code may never reach
 * the cleanup stage
 * 2 resources might need to be released at multiple locations in the
 * code, making it difficult to ensure comprehensive cleanup across all possible
 * execution paths
 * 3 developers may simply overlook releasing the resource altogether
 * due to human factor
 *
 * RAII solves resource management by embedding it into object-oriented design. The key
 * principle is that the management class takes full ownership of the resource, handling
 * both its allocation and deallocation internally. This encapsulation means developers
 * working with the class don't need to manually manage resources - they simply use the
 * objects, and the management class automatically handles cleanup. The core idea is
 * simple: whoever owns the resource is responsible for its lifecycle
 *
 * RAII has three core components
 * 1 The constructor acquires and initializes the resource
 * 2 The destructor handles automatic resource cleanup
 * 3 Stack allocation ensures scope-based lifetime management
 */

#include "../include/NoRaii.hpp"
#include "../include/Raii.hpp"
int main() {
    ExNoRaii();
    ExRaii();
    return 0;
}
