#include <iostream>
#include <vector>

uint64_t factorial(int x)
{
    uint64_t silnia = 1;
    for (int i = 1; i <= x; i++)
    {
        silnia *= i;
    }
    return silnia;
}

int main()
{
    uint64_t result = factorial(15);
    std::cout << result << std::endl;

    return 0;
}
