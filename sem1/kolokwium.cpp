

#include <iostream>
#define ELFY 5

using namespace std;

class elfiaZygota {
protected:
    int prod;

public:
    virtual ~elfiaZygota() { ; }
    virtual int zwrocProd() = 0;
};

class elf : public elfiaZygota {
public:
    elf()
    {
        prod = 5;
        cout << "Tu elf." << endl;
    }
    virtual int zwrocProd() { return prod; }
};

class superElf : public elf {
protected:
    int sila;

public:
    superElf(int argProd, int argSila)
    {
        prod = argProd;
        sila = argSila;
        cout << "Tu superElf" << endl;
    }
    int zwrocProd() { return prod * sila; }
};

class elfMutant : public elfiaZygota {
public:
    elfMutant()
    {
        prod = -2;
        cout << "Tu elfMutant" << endl;
    }
    int zwrocProd() { return prod; }
};

class goblin : public elfMutant {
protected:
    int sila;

public:
    goblin(int argProd, int argSila)
    {
        prod = -argProd;
        sila = argSila;
        cout << "Tu goblin" << endl;
    }
    int zwrocProd() { return prod * sila; }
};

goblin operator+(goblin& s, elf& d)
{
    goblin tmp(d.zwrocProd() + s.zwrocProd(), 2);
    return tmp;
}

void obliczProdukcje(elfiaZygota* tablicaElfow[ELFY])
{
    int produkcja = 0;
    cout << "Czy elfy dadza rade?" << endl;

    for (int i = 0; i < ELFY; i++) {
        produkcja += tablicaElfow[i]->zwrocProd();
    }

    if (produkcja > 0) {
        cout << "TAK!" << endl;
    }
    else {
        cout << "nie :(" << endl;
    }
}

int main()
{
    elfiaZygota* tablicaElfow[ELFY];
    elf Lesnik;
    tablicaElfow[0] = (elfiaZygota*)&Lesnik; // tab[0] =adres na klase wskaz elfiaZygoda
    tablicaElfow[1] = new elfMutant();
    tablicaElfow[2] = new elf();
    tablicaElfow[3] = new superElf(6, 3);
    tablicaElfow[4] = new goblin(5, 3);
    obliczProdukcje(tablicaElfow);
    cout << "Oj, jeden z elfów zmutował..." << endl;
    goblin Gobus(1, 1);
    Gobus = Gobus + Lesnik;
    tablicaElfow[0] = (elfiaZygota*)&Gobus;
    obliczProdukcje(tablicaElfow);
    for (int i = 1; i < ELFY; i++) {
        delete tablicaElfow[i];
    }
}
