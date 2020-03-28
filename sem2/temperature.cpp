#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <sstream>
struct Temp
{
    std::string data;
    std::string czas;
    double predkosc;
    double temp_dzw;
    double cisnienie;
    double temp;
    double wilgotnosc;
    double kompas;
    double predkosc_uv;
    double predkosc_wiatru;
    double kierunek;
    double wysokosc;
    double temp_wew;
};
bool greaterThan(const Temp &a, const Temp &b)
{
    return a.temp < b.temp;
}

int main()
{
    std::ifstream file("temp02-2020.csv");
    std::vector<Temp> tablica;
    if (file.is_open())
    {

        std::string line;
        std::getline(file, line);
        while (std::getline(file, line))
        {
            std::stringstream str(line);
            Temp tp;
            std::getline(str, tp.data, ',');
            std::getline(str, tp.czas, ',');
            std::string double_str;
            std::getline(str, double_str, ',');
            tp.predkosc = std::stod(double_str);
            std::getline(str, double_str, ',');
            tp.temp_dzw = std::stod(double_str);
            std::getline(str, double_str, ',');
            tp.cisnienie = std::stod(double_str);
            std::getline(str, double_str, ',');
            tp.temp = std::stod(double_str);
            std::getline(str, double_str, ',');
            tp.wilgotnosc = std::stod(double_str);
            std::getline(str, double_str, ',');
            tp.kompas = std::stod(double_str);
            std::getline(str, double_str, ',');
            tp.predkosc_uv = std::stod(double_str);
            std::getline(str, double_str, ',');
            tp.predkosc_wiatru = std::stod(double_str);
            std::getline(str, double_str, ',');
            tp.kierunek = std::stod(double_str);
            std::getline(str, double_str, ',');
            tp.wysokosc = std::stod(double_str);
            std::getline(str, double_str, ',');
            tp.temp_wew = std::stod(double_str);
            tablica.emplace_back(tp);
        }
    }
    std::sort(tablica.begin(), tablica.end(), greaterThan);
    std::cout << "Min: " << std::endl
              << "Data: " << tablica[0].data << " Temp: " << tablica[0].temp << std::endl
              << "Max: " << std::endl
              << "Data: " << tablica[tablica.size() - 1].data << " Temp: " << tablica[tablica.size() - 1].temp << std::endl;
    std::cout << "Mediana: ";

    if (tablica.size() % 2)
    {
        std::cout << tablica[(tablica.size() + 1) / 2].temp << std::endl;
    }
    else
    {
        double srednia = (tablica[tablica.size() / 2].temp + tablica[(tablica.size() / 2) + 1].temp) / 2;
        std::cout << srednia << std::endl;
    }

    return 0;
}
