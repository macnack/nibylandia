#include <iostream>
using namespace std;
class zwierze
{
public:
    zwierze() { cout << "Stworzono zwierze. " << endl; };
    virtual void opis() { cout << "Klasa zwierze. " << endl; };
};
class ssak : public zwierze
{
public:
    ssak() { cout << "Stworzono ssak. " << endl; };
    void opis() { cout << "Klasa ssak. " << endl; };
};
class czlowiek : public ssak
{
public:
    czlowiek() { cout << "Stworzono czlowiek. " << endl; };
    void opis() { cout << "Klasa czlowiek. " << endl; };
};
class ptak : public zwierze
{
public:
    ptak() { cout << "Stworzono ptak. " << endl; };
    void opis() { cout << "Klasa ptak. " << endl; };
};

zwierze *funkcja()
{
    int x = rand() % 5;
    cout << "Beben maszyny jest pusty, prosze o zwolnienie blokady..." << endl;
    switch (x)
    {
    case (0):
    {
        return new zwierze;
        break;
    }
    case (1):
    {
        return new ssak;
        break;
    }
    case (2):
    {
        return new czlowiek;
        break;
    }
    case (3):
    {
        return new ptak;
        break;
    }
    case (4):
    {
        return NULL;
    }
    }
};

int main()
{
    zwierze *wsk = new zwierze;

    int petla;
    cout << "Podaj liczbe petli: " << endl;
    cin >> petla;
    for (int i = 0; i < petla; i++)
    {
        zwierze *wsk = funkcja();
        if (wsk != NULL)
        {
            cout << "##########################" << endl;
            wsk->opis();
            cout << "##########################" << endl;
        }
        else
        {
            cout << "Pusty los - obiektt nie stworzony!" << endl;
        }
        delete wsk;
    }
    cin.get();

    return 0;
}
