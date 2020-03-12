#include <iostream>
#include <vector>
#include <cmath>

bool is_prime(int N)
{
    bool czy_podzielnik = false;
    for (int i = 2; i < N / 2; i++)
    {
        if (N % i == 0)
        {
            czy_podzielnik = true;
        }
    }
    return !czy_podzielnik;
}
void is_prime_number(int od, int zakres)
{
    for (int i = 2; i <= zakres; i++)
    {
        if (i > od)
        {
            if (i != 4)
            {
                if (is_prime(i))
                {
                    std::cout << i << ", ";
                }
            }
        }
    }
}

int main()
{
    int prime_or_not_prime = 13;
    if (is_prime(prime_or_not_prime))
    {
        std::cout << prime_or_not_prime << " is prime!" << std::endl;
    }
    else
    {
        std::cout << prime_or_not_prime << " is not prime!" << std::endl;
    }
    int dolna_g, gorna_g;
    std::cin >> dolna_g >> gorna_g;
    is_prime_number(dolna_g, gorna_g);
    std::cout << std::endl;
    return 0;
}
