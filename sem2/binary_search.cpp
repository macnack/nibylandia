#include <iostream>
#include <vector>
int binary_search(const std::vector<double> &wektor, const double szukana)
{
    int poczatek, koniec, srodek;
    poczatek = 0;
    koniec = wektor.size() - 1;
    while (poczatek <= koniec)
    {
        srodek = poczatek + (koniec - poczatek) / 2;
        if (wektor[srodek] == szukana)
        {
            return srodek;
        }
        else if (wektor[srodek] < szukana)
        {
            poczatek = srodek + 1;
        }
        else
        {
            koniec = srodek - 1;
        }
    }
    return -1;
}
int main()
{
    std::vector<double> wektor = {1, 2, 5, 8, 9, 11, 15};
    int found = binary_search(wektor, 5);
    std::cout << "Znaleziono: ";
    std::cout << found;
    return 0;
}
