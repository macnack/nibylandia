#include <iostream>
#include <vector>
#include <string>

std::string find_and_replace(std::string &string, std::string find, std::string replace)
{
    std::size_t pos = 0, found;
    std::vector<std::size_t> tab_found;
    while (found != std::string::npos)
    {
        found = string.find(find, pos);
        if (found != std::string::npos)
        {
            tab_found.push_back(found);
            pos = found + 1;
        }
    }
    for (std::vector<std::size_t>::iterator it = tab_found.end() - 1; it != tab_found.begin() - 1; it--)
    {
        string.replace(*it, find.size(), replace);
    }
    return string;
}

int main()
{ //                   0123456789*123456789*123456
    std::string input = "Ala ma kota, kot zjadl Ale!";
    std::string output = find_and_replace(input, "kot", "hefalump");
    // wynik: "Ala ma hefalumpa, hefalump zjadl Ale!"
    std::cout << output << std::endl;

    return 0;
}
