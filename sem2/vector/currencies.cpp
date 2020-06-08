#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

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
        out << "Euro: " << et.eur << " " << "Usd: " << et.usd << std::endl;
    }
    return out;
}
std::vector<Exchange_rate> sort_euro(std::vector<Exchange_rate> &wektor)
{
    std::vector<Exchange_rate> vec = wektor;
    int rozmiar = vec.size();
    bool posortowane = true;
    std::vector<Exchange_rate> tmp(1);
    do
    {
        rozmiar--;
        posortowane = false;
        for (int i = 0; i < rozmiar; i++)
        {
            if (vec[i].eur > vec[i + 1].eur)
            {

                tmp[0] = vec[i];
                vec[i] = vec[i + 1];
                vec[i + 1] = tmp[0];
                posortowane = true;
            }
        }

    } while (posortowane);
    return vec;
}
std::vector<Exchange_rate> sort_usd(const std::vector<Exchange_rate> &wektor)
{
    std::vector<Exchange_rate> vec = wektor;
    int rozmiar = vec.size();
    bool posortowane = true;
    std::vector<Exchange_rate> tmp(1);
    do
    {
        rozmiar--;
        posortowane = false;
        for (int i = 0; i < rozmiar; i++)
        {
            if (vec[i].usd > vec[i + 1].usd)
            {

                tmp[0] = vec[i];
                vec[i] = vec[i + 1];
                vec[i + 1] = tmp[0];
                posortowane = true;
            }
        }

    } while (posortowane);
    return vec;
}
int binary_search(const std::vector<Exchange_rate> &wektor, const double szukana){
    int poczatek, koniec, srodek;
    poczatek = 0;
    koniec = wektor.size()-1;
    while (poczatek <= koniec) {
        srodek = poczatek + (koniec - poczatek)/2;
        if(wektor[srodek].usd == szukana){
            return srodek;
        }
        else if( wektor[srodek].usd < szukana ){
            poczatek = srodek + 1;
        }
        else{
            koniec = srodek - 1;
        }
    }
    return -1;
}
int main()
{
    std::ifstream file("kursy_usd_eur.csv");
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
    std::vector<Exchange_rate> sorted_eur = sort_euro(rates);
    std::cout << "EUR od najmniejszego: " << std::endl;
    for(auto it = sorted_eur.begin(); it != sorted_eur.begin()+10; it++){
        std::cout << "Data: " << it->date << " Kurs: " << it->eur << std::endl;
    }
    std::cout << "USD od najwiekszego: " << std::endl;
    std::vector<Exchange_rate> sorted_usd = sort_usd(rates);
    for(auto it = sorted_usd.end()-1 ; it != sorted_usd.end()-11; it--){
        std::cout << "Data: " << it->date << " Kurs: " << it->usd << std::endl;
    }
    int found = binary_search(sorted_usd, 3.9011);
    std::cout << "binary search: " << found << std::endl;
    if( found != -1){
    std::cout << "Data: " << sorted_usd[found].date << std::endl;
	}
    return 0;
}
