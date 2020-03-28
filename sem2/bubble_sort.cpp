#include <iostream>
#include <vector>

void show(std::vector<int> &a)
{
    std::cout << "|";
    for (std::vector<int>::iterator it = a.begin(); it != a.end(); it++)
    {
        std::cout << *it << "|";
    }
    std::cout << "\n";
}
void sortowanie_bombelkowe(std::vector<int> &vec)
{
    int rozmiar = vec.size();
    bool posortowane = true;
    do
    {
        rozmiar--;
        posortowane = false;
        for (int i = 0; i < rozmiar; i++)
        {
            if (vec[i] > vec[i + 1])
            {
                std::vector<int> tmp(1);
                tmp[0] = vec[i];
                vec[i] = vec[i + 1];
                vec[i + 1] = tmp[0];
                posortowane = true;
            }
        }

    } while (posortowane);
}

int main()
{
    std::vector<int> vector = {5, 4, 3, 2, 1, 0};
    show(vector);
    sortowanie_bombelkowe(vector);
    show(vector);
}
