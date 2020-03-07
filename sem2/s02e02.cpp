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
std::vector<std::string> split(std::string &zdanie)
{
    std::vector<std::string> string;
    std::size_t pos = 0, found;
    std::vector<std::size_t> tab_found;
    while (found != std::string::npos)
    {
        found = zdanie.find(" ", pos);
        if (found != std::string::npos)
        {
            tab_found.push_back(found);
            pos = found + 1;
        }
    }
    tab_found.push_back(zdanie.size() + 1);
    pos = 0;
    std::string tmp;
    for (std::vector<std::size_t>::iterator it = tab_found.begin(); it != tab_found.end(); it++)
    {
        tmp = zdanie.substr(pos, *it - pos);
        pos = *it + 1;
        if (tmp != "")
            string.push_back(tmp);
    }
    show(string);
    return string;
}
std::vector<std::string> split(std::string &zdanie, char znak)
{
    std::vector<std::string> string;
    std::size_t pos = 0, found;
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
    for (std::vector<std::size_t>::iterator it = tab_found.begin(); it != tab_found.end(); it++)
    {
        tmp = zdanie.substr(pos, *it - pos);
        pos = *it + 1;
        if (tmp != "")
            string.push_back(tmp);
    }
    show(string);
    return string;
}

int main()
{
    std::string sentence = "Ala ma kota";
    std::vector<std::string> words = split(sentence);
    // wynik: {"Ala", "ma", "kota"}
    std::string csv = "Mount Everest,8848,1953";
    std::vector<std::string> data = split(csv, ',');
    // wynik: {"Mount Everest", "8848", "1953"}

    return 0;
}