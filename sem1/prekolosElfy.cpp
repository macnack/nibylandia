#include <iostream>
#include <string>
using namespace std;
class elf
{
protected:
    int prod, zycie;

public:
    static int liczbaElfow;
    void przedstaw() { cout << prod << " " << zycie; }
    virtual int zrobZabawke(int dzien)
    {
        if (dzien < zycie)
        {
            return prod;
        }
        else
        {
            return 0;
        }
    }
    elf()
    {
        liczbaElfow++;
        prod = zycie = 5;
        cout << "Tu elf 1." << endl;
    }
    elf(int temp_prod, int temp_zycie)
    {
        liczbaElfow++;
        zycie = temp_zycie;
        prod = temp_zycie;
        cout << "Tu elf 2." << endl;
    }
    virtual ~elf() { ; }
};
class superElf : public elf
{
    int sila;

public:
    static int liczbaSuperElfow;
    virtual int zrobZabawke(int dzien)
    {
        if (dzien < zycie)
        {
            return sila * prod;
        }
        else
        {
            return 0;
        }
    }
    superElf(int temp_zycie, int temp_prod, int temp_sila)
    {
        liczbaSuperElfow++;
        zycie = temp_zycie;
        prod = temp_prod;
        sila = temp_sila;
        cout << "Tu jest superElf" << endl;
    }
};
int elf::liczbaElfow = 0;
int superElf::liczbaSuperElfow = 0;
const int ELFY = 4;
string czyElfySieWyrobia(elf *tablicaElfow[ELFY], int d, const int z)
{
    int zrobione_prezenty = 0;
    for (int i = 0; i < ELFY; i++)
    {
        zrobione_prezenty += tablicaElfow[i]->zrobZabawke(d);
    }
    if (zrobione_prezenty < z)
    {
        return "Elfy nie wyrobily sie, w tym roku pracownicy Amazona uratuja swieta.";
    }
    else
        return "Elfy wyrobily sie. Wesolych Swiat!";
}

int main()
{
    elf *tablicaElfow[4];

    tablicaElfow[0] = new elf;
    tablicaElfow[1] = new superElf(3, 5, 3);
    tablicaElfow[2] = new elf(5, 2);
    tablicaElfow[3] = new elf;
    cout << czyElfySieWyrobia(tablicaElfow, 2, 20);

    cout << endl;
    cout << "Elfow jest: " << elf::liczbaElfow << endl;
    cout << "W tym super elfow jest: " << superElf::liczbaSuperElfow << endl;

    return 0;
}
