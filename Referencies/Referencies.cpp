#include <cstdint>
#include <iostream>

struct Result
{
    int32_t value;
};

bool Divide(int32_t a, int32_t b, Result& result)
{
    printf("inside divide func &result=%p, with size=%llu bytes\n", &result, sizeof(result));

    if (b == 0) return false;

    result = Result{a / b};
    return true;
}

int main()
{
    Result result;
    printf("before divide func &result=%p, with size=%llu bytes\n", &result, sizeof(result));

    constexpr int32_t a = 16;
    constexpr int32_t b = 2;

    if (Divide(a, b, result))
    {
        printf("after  divide func &result=%p, with size=%llu bytes\n", &result, sizeof(result));
        printf("a=%d, b=%d, result.value=%d", a, b, result.value);
    }
    return 0;
}
