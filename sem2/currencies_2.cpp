#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
struct Exchange_rate
{
    std::string date;
    double usd;
    double eur;
    std::string table_id;
};
std::ostream &operator<<(std::ostream &out, const std::vector<Exchange_rate> &wektor)
{
    for (Exchange_rate et : wektor)
    {
        out << "Data: " << et.date << std::endl;
        out << "Euro: " << et.eur << " "
            << "Usd: " << et.usd << std::endl;
    }
    return out;
}
bool operator<(int x, const Exchange_rate &r1)
{
    return r1.usd < x;
}
bool operator<(const Exchange_rate &r2, int x)
{
    return x < r2;
}
int main()
{
    std::ifstream file("/home/maciek/work/kursy_usd_eur.csv");
    std::vector<Exchange_rate> rates;
    if (file.is_open())
    {
        std::string line;
        std::getline(file, line);
        while (std::getline(file, line))
        {
            std::stringstream str(line);

            Exchange_rate er;
            std::getline(str, er.date, ',');
            std::string double_str;
            std::getline(str, double_str, ',');
            er.usd = std::stod(double_str);
            std::getline(str, double_str, ',');
            er.eur = std::stod(double_str);
            std::getline(str, er.table_id, ',');
            rates.emplace_back(er);
        }
    }
    std::sort(rates.begin(), rates.end(), [](const Exchange_rate &r1, const Exchange_rate &r2) { return r1.eur < r2.eur; });
    std::cout << "EUR od najmniejszego: " << std::endl;
    for (auto it = rates.begin(); it != rates.begin() + 10; it++)
    {
        std::cout << "Data: " << it->date << " Kurs: " << it->eur << std::endl;
    }
    std::cout << "USD od najwiekszego: " << std::endl;
    std::sort(rates.begin(), rates.end(), [](const Exchange_rate &r1, const Exchange_rate &r2) { return r1.usd > r2.usd; });
    for (auto it = rates.begin(); it != rates.begin() + 10; it++)
    {
        std::cout << "Data: " << it->date << " Kurs: " << it->usd << std::endl;
    }
    std::sort(rates.begin(), rates.end(), [](const Exchange_rate &r1, const Exchange_rate &r2) { return r1.usd < r2.usd; });
    std::pair<std::vector<Exchange_rate>::const_iterator, std::vector<Exchange_rate>::const_iterator> bounds;
    bounds = std::equal_range(rates.begin(), rates.end(), 3.9011);
    if ((bounds.first - rates.begin()))
    {
        std::cout << (bounds.first - rates.begin()) << std::endl
                  << rates[(bounds.first - rates.begin())].date << std::endl;
    }
    else
    {
        std::cout << std::endl
                  << "Nie znaleziono. " << std::endl;
    }
    return 0;
}
