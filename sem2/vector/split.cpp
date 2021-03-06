#include <iostream>
#include <vector>
#include <string>
void show(std::vector<std::string> &string)
{
    for (unsigned int i = 0; i < string.size(); i++)
    {
        if (i == string.size() - 1)
        {
            std::cout << "\"" << string[i] << "\"}" << std::endl;
        }
        else if (i == 0)
        {
            std::cout << "{\"" << string[i] << "\", ";
        }
        else
        {
            std::cout << "\"" << string[i] << "\", ";
        }
    }
    std::cout << std::endl;
}
std::vector<std::string> split(std::string &zdanie, char znak = ' ')
{
    std::vector<std::string> string;
    std::size_t pos = 0, found = 0;
    std::vector<std::size_t> tab_found;
    while (found != std::string::npos)
    {
        found = zdanie.find(znak, pos);
        if (found != std::string::npos)
        {
            tab_found.push_back(found);
            pos = found + 1;
        }
    }
    tab_found.push_back(zdanie.size() + 1);
    pos = 0;
    std::string tmp;
    for (size_t &it : tab_found)
    {
        tmp = zdanie.substr(pos, it - pos);
        pos = it + 1;
        if (tmp != "")
            string.push_back(tmp);
    }
    return string;
}

int main()
{
    std::string sentence = "Ala ma kota";
    std::vector<std::string> words = split(sentence);
    show(words);
    // wynik: {"Ala", "ma", "kota"}
    std::string csv = "Mount Everest,8848,1953";
    char znak = ',';
    std::vector<std::string> data = split(csv,znak);
    show(data);
    // wynik: {"Mount Everest", "8848", "1953"}

    return 0;
}