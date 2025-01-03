#include <cstdio>
#include <thread>

int* StackExpand(int a, int b) {
    int k = a + b;
    printf("3: %p | +60B without -O optimizations\n", &k);
    return &k;  // returns a pointer to non-existing var
}

void StackOverflow(int* startp) {
    printf("stack bottom: %p,\n", startp);
    int j = 2;
    printf("current : %p\n", &j);
    StackOverflow(startp);  // recursive call to overflow the stack
}

int main() {
    // int i = 1;
    // StackOverflow(&i);

    int i = 1;
    printf("1: %p | start\n", &i);

    int j = 2;
    printf("2: %p | +4B on int j declaration\n", &j);

    printf("4: %p | dangling pointer on function return as the stack contracts\n",
           StackExpand(i, j));

    int l = 5;
    printf("5: %p | -56B (-60 on exit Func and +4 on declaring int l)\n", &l);

    std::thread th([]() {
        int l = 6;
        printf(
            "6: %p | +255KB as the new thread gets own fixed stack from the "
            "process virtual memory space\n",
            &l);
    });

    th.join();
    return 0;
}
