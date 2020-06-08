#include <iostream>
#include <string>
#include <vector>

std::string find_longest_word(std::string slowo)
{
    size_t found = 0;
    std::vector<size_t> poczatek;
    poczatek.push_back(found);
    while (found != std::string::npos)
    {
        found = slowo.find(" ", found + 1);
        if (found != std::string::npos)
        {
            poczatek.push_back(found + 1);
        }
    }
    int dl;
    int max = 0;
    int j = 0;
    poczatek.push_back(slowo.size() + 1);
    for (int i = 0; i < poczatek.size() - 1; i++)
    {
        dl = poczatek[i + 1] - poczatek[i] - 1;
        if (dl > max)
        {
            max = dl;
            j = poczatek[i];
        }
    }
    std::string tmp = slowo.substr(j, dl);

    return tmp;
}

int main()
{ //                     0123456789*123456789*123456789*1234
    std::string input = "Ala ma kota, kot jezdzi na Roombie";
    std::string output = find_longest_word(input); // 7
    std::cout << output;
    return 0;
}
