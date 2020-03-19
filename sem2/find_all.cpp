#include <iostream>
#include <vector>

void show(std::vector<size_t> &tab)
{
    for (unsigned int i = 0; i < tab.size(); i++)
    {
        if (i == tab.size() - 1)
        {
            std::cout << "\"" << tab[i] << "\"}" << std::endl;
        }
        else if (i == 0)
        {
            std::cout << "{\"" << tab[i] << "\", ";
        }
        else
        {
            std::cout << "\"" << tab[i] << "\", ";
        }
    }
    std::cout << std::endl;
}

std::vector<size_t> find_all(const std::string &string, const char &znak){
    std::size_t pos = 0, found;
    std::vector<std::size_t> tab_found;
    while (found != std::string::npos)
    {
        found = string.find(znak, pos);
        if (found != std::string::npos)
        {
            tab_found.push_back(found);
            pos = found + 1;
        }
    }
    return tab_found;
}

int main(){
    std::string input = "Ala ma kota";
    std::vector<size_t> pos = find_all(input, 'a');
    show(pos);
}
