#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

enum class TypRosliny
{
    Owoc,
    Warzywo
};

struct Roslina
{
    TypRosliny typ;
    std::string nazwa;
};

using Koszyk = std::vector<Roslina>;

std::ostream &operator<<(std::ostream &out, const Roslina &roslina)
{
    out << roslina.nazwa;
    switch (roslina.typ)
    {
    case TypRosliny::Owoc:
        out << " typ Owoc";
        return out;
    case TypRosliny::Warzywo:
        out << " typ Warzywo";
        return out;
    }
    return out;
}
bool czy_jest_gruszka(const Koszyk &koszyk)
{
    auto x = std::find_if(koszyk.begin(), koszyk.end(), [](const Roslina &roslina) { return roslina.nazwa == "gruszka"; });
    if (x != koszyk.end())
    {
        return true;
    }
    return false;
}
bool czy_same_owoce(const Koszyk &koszyk)
{
    return std::all_of(koszyk.begin(), koszyk.end(),
                       [](const Roslina &roslina) { return roslina.typ == TypRosliny::Owoc; });
}
bool czy_same_warzywa(const Koszyk &koszyk)
{
    return std::all_of(koszyk.begin(), koszyk.end(),
                       [](const Roslina &roslina) { return roslina.typ == TypRosliny::Warzywo; });
}
bool at_least_one_owoc(const Koszyk &koszyk)
{
    return std::any_of(koszyk.begin(), koszyk.end(),
                       [](const Roslina &roslina) { return roslina.typ == TypRosliny::Owoc; });
}
bool at_least_one_warzywo(const Koszyk &koszyk)
{
    return std::any_of(koszyk.begin(), koszyk.end(),
                       [](const Roslina &roslina) { return roslina.typ == TypRosliny::Warzywo; });
}
bool none_of_owocu(const Koszyk &koszyk)
{
    return std::none_of(koszyk.begin(), koszyk.end(),
                        [](const Roslina &roslina) { return roslina.typ == TypRosliny::Owoc; });
}
bool none_of_warzywa(const Koszyk &koszyk)
{
    return std::none_of(koszyk.begin(), koszyk.end(),
                        [](const Roslina &roslina) { return roslina.typ == TypRosliny::Warzywo; });
}
int zlicz_rosliny_na_litere_m(const Koszyk &koszyk)
{
    return std::count_if(koszyk.begin(), koszyk.end(),
                         [](const Roslina &roslina) { return roslina.nazwa[0] == 'M' || roslina.nazwa[0] == 'm'; });
}
int zlicz_owoce(const Koszyk &koszyk)
{
    return std::count_if(koszyk.begin(), koszyk.end(),
                         [](const Roslina &roslina) { return roslina.typ == TypRosliny::Owoc; });
}
int zlicz_warzywo(const Koszyk &koszyk)
{
    return std::count_if(koszyk.begin(), koszyk.end(),
                         [](const Roslina &roslina) { return roslina.typ == TypRosliny::Warzywo; });
}
void usun_zaczynajace_sie_od(Koszyk &koszyk)
{
    koszyk.erase(std::remove_if(koszyk.begin(), koszyk.end(),
                                [](const Roslina &roslina) { return roslina.nazwa[0] == 'G' || roslina.nazwa[0] == 'g'; }));
}
std::ostream &operator<<(std::ostream &out, const Koszyk &koszyk)
{
    for (auto k : koszyk)
    {
        out << k << std::endl;
    }
    return out;
}

bool operator<(const Roslina &r1, const Roslina &r2)
{
    return r1.nazwa < r2.nazwa;
}

int main()
{

    Roslina apple = {TypRosliny::Owoc, "jablko"};
    Roslina banan = {TypRosliny::Owoc, "banan"};
    Roslina gruszka = {TypRosliny::Owoc, "gruszka"};
    Roslina anan = {TypRosliny::Owoc, "ananas"};
    Roslina kiwi = {TypRosliny::Owoc, "kiwi"};
    Roslina marchewka = {TypRosliny::Warzywo, "marchewka"};
    Roslina pomidor = {TypRosliny::Warzywo, "pomidor"};

    Koszyk koszyk;
    koszyk.push_back(apple);
    koszyk.push_back(marchewka);
    koszyk.push_back(banan);
    koszyk.push_back(anan);
    Koszyk koszyk2;
    koszyk2.push_back(apple);
    koszyk2.push_back(gruszka);
    koszyk2.push_back(anan);
    koszyk2.push_back(pomidor);
    koszyk2.push_back(kiwi);

    std::cout << "Czy w koszyku jest gruszka? " << std::endl;
    if (czy_jest_gruszka(koszyk))
    {
        std::cout << "Tak!" << std::endl;
    }
    else
    {
        std::cout << "Nie, juz dodaje do koszyka. ";
        Roslina gruszka = {TypRosliny::Owoc, "gruszka"};
        koszyk.push_back(gruszka);
        std::cout << "(+1 gruszka do koszyka)" << std::endl;
    }
    std::cout << "Koszyk Małgosi: \n{" << std::endl
              << koszyk << "}\n\tCzy naprawdę zanosisz Babci same owoce? " << std::endl;
    if (czy_same_owoce(koszyk))
    {
        std::cout << "Tak, same owoce." << std::endl;
    }
    if (czy_same_warzywa(koszyk))
    {
        std::cout << "Nie, same warzywa." << std::endl;
    }
    if (at_least_one_owoc(koszyk))
    {
        std::cout << "Nie, jest przynajmniej jeden owoc." << std::endl;
    }
    if (at_least_one_warzywo(koszyk))
    {
        std::cout << "Nie, jest przynajmniej jedno warzywo." << std::endl;
    }
    if (none_of_owocu(koszyk))
    {
        std::cout << "Nie ma zadnego owocu." << std::endl;
    }
    if (none_of_warzywa(koszyk))
    {
        std::cout << "Nie ma zadnego warzywa." << std::endl;
    }
    int owoce = zlicz_owoce(koszyk);
    int warzywa = zlicz_warzywo(koszyk);
    std::cout << std::endl
              << "Ilosc owocow: " << owoce << std::endl
              << "Ilosc warzyw: " << warzywa << std::endl;

    usun_zaczynajace_sie_od(koszyk);

    std::cout << std::endl
              << "Małgosia zjadła wszystko na G" << std::endl
              << koszyk << std::endl;

    std::sort(koszyk.begin(), koszyk.end(), [](const Roslina &r1, const Roslina &r2) { return r1.nazwa < r2.nazwa; });
    std::sort(koszyk2.begin(), koszyk2.end(), [](const Roslina &r1, const Roslina &r2) { return r1.nazwa < r2.nazwa; });

    std::cout << "Koszyk Malgosi: " << std::endl
              << koszyk << std::endl
              << "Koszyk Marty: " << std::endl
              << koszyk2 << std::endl;

    Koszyk koszyk_wspolne;
    std::set_intersection(koszyk.begin(), koszyk.end(),
                          koszyk2.begin(), koszyk2.end(),
                          std::back_inserter(koszyk_wspolne));
    std::sort(koszyk_wspolne.begin(), koszyk_wspolne.end(), [](const Roslina &r1, const Roslina &r2) { return r1.nazwa < r2.nazwa; });

    std::cout << "Porównanie wspolnych elementów: " << std::endl;
    std::cout << koszyk_wspolne << std::endl;

    std::set_difference(koszyk.begin(), koszyk.end(),
                        koszyk2.begin(), koszyk2.end(),
                        std::inserter(koszyk_wspolne, koszyk_wspolne.begin()));
    std::sort(koszyk_wspolne.begin(), koszyk_wspolne.end(), [](const Roslina &r1, const Roslina &r2) { return r1.nazwa < r2.nazwa; });

    std::cout << std::endl
              << "Elementy rozne: " << std::endl
              << koszyk_wspolne << std::endl;

    Koszyk duzy_koszyk;
    std::set_union(koszyk.begin(), koszyk.end(),
                   koszyk2.begin(), koszyk2.end(),
                   std::back_inserter(duzy_koszyk));

    std::cout << "Duzy koszyk: " << std::endl
              << duzy_koszyk << std::endl;
    return 0;
}
