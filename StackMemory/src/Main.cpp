#include <cstdio>

void StackExpand(int a, int b) {
    int k = a + b;
    printf("3: %p | +60bytes without -O optimizations\n", &k);
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
    printf("2: %p | +4bytes on int j declaration\n", &j);

    StackExpand(i, j);

    int l = 4;
    printf("4: %p | -56bytes (-60 on exit Func and +4 on declaring int l)\n", &l);

    return 0;
}
