#include <iostream>

void gcd(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    std::cout << "NWD: " << a << std::endl;
}

int main()
{
    int jeden;
    int dwa;
    while (dwa != 0)
    {
        std::cin >> jeden >> dwa;
        gcd(jeden, dwa);
    }
    return 0;
}
