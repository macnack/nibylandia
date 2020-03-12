#include <iostream>
using namespace std;

class Zwierze
{
public:
    string zwierze = "Zwierze";
    int wiek;
    int masa;
    string imie;
    Zwierze();
    void patrz();
    void oddychaj();
    void zyj();
    string getZwierze() { return zwierze; }
};

class Ryba : public Zwierze
{
    string klasa = "Ryba";

public:
    Ryba();
    void Plywaj();
    string getKlasa() { return klasa; }
};

class Ssak : public Zwierze
{
    string klasa = "Ssak ";

public:
    Ssak();
    void Plywaj();
    string getKlasa() { return klasa; }
};

class Ptak : public Zwierze
{
    string klasa = "Ptak ";

public:
    Ptak();
    void Lataj();
    string getKlasa() { return klasa; }
};

class Welonek : public Ryba
{
    string gatunek = "Welonek ";

public:
    Welonek(string n);
    void Przedstaw();
    string getGatunek() { return gatunek; }
};
class Nemo : public Ryba
{
    string gatunek = "Nemo ";

public:
    Nemo(string n);
    void Przedstaw();
    string getGatunek() { return gatunek; }
};
class Karp : public Ryba
{
    string gatunek = "Karp ";

public:
    Karp(string n);
    void Przedstaw();
    string getGatunek() { return gatunek; }
};

class Pies : public Ssak
{
    string gatunek = "Pies ";

public:
    Pies(string n);
    void Przedstaw();
    string getGatunek() { return gatunek; }
};
class Lew : public Ssak
{
    string gatunek = "Lew ";

public:
    Lew(string n);
    void Przedstaw();
    string getGatunek() { return gatunek; }
};
class Slon : public Ssak
{
    string gatunek = "Slon ";

public:
    Slon(string n);
    void Przedstaw();
    string getGatunek() { return gatunek; }
};

class Kanarek : public Ptak
{
    string gatunek = "Kanarek ";

public:
    Kanarek(string n);
    void Przedstaw();
    string getGatunek() { return gatunek; }
};
class Golob : public Ptak
{
    string gatunek = "Golob ";

public:
    Golob(string n);
    void Przedstaw();
    string getGatunek() { return gatunek; }
};
class Papuga : public Ptak
{
    string gatunek = "Papuga ";

public:
    Papuga(string n);
    void Przedstaw();
    string getGatunek() { return gatunek; }
};

Zwierze::Zwierze()
{
    cout << "Stworzono Zwierze" << endl;
}
Ryba::Ryba()
{
    cout << "Stworzono Ryba" << endl;
}
Ptak::Ptak()
{
    cout << "Stworzono Ptak" << endl;
}
Ssak::Ssak()
{
    cout << "Stworzono Ssak" << endl;
}
Welonek::Welonek(string n)
{
    imie = n;
    cout << "Stworzono Welonek" << endl;
    cout << Welonek::imie << endl;
}
Nemo::Nemo(string n)
{
    imie = n;
    cout << "Stworzono Welonek" << endl;
    cout << Nemo::imie << endl;
}
Karp::Karp(string n)
{
    imie = n;
    cout << "Stworzono Welonek" << endl;
    cout << Karp::imie << endl;
}
Lew::Lew(string n)
{
    imie = n;
    cout << "Stworzono Lew" << endl;
    cout << Lew::imie << endl;
}
Pies::Pies(string n)
{
    imie = n;
    cout << "Stworzono Pies" << endl;
    cout << Pies::imie << endl;
}
Slon::Slon(string n)
{
    imie = n;
    cout << "Stworzono Slon" << endl;
    cout << Slon::imie << endl;
}
Kanarek::Kanarek(string n)
{
    imie = n;
    cout << "Stworzono Kanarek" << endl;
    cout << Kanarek::imie << endl;
}
Papuga::Papuga(string n)
{
    imie = n;
    cout << "Stworzono Papuga" << endl;
    cout << Papuga::imie << endl;
}
Golob::Golob(string n)
{
    imie = n;
    cout << "Stworzono Golob" << endl;
    cout << Golob::imie << endl;
}
void Welonek::Przedstaw()
{
    cout << "Jestem " << getGatunek() << imie << endl;
    cout << "Jestem elementem klasy " << getGatunek() << "dziedziczacym z klasy "
         << getKlasa() << "ktora dziedziczyla z klasy " << getZwierze() << endl;
}
void Nemo::Przedstaw()
{
    cout << "Jestem " << getGatunek() << imie << endl;
    cout << "Jestem elementem klasy " << getGatunek() << "dziedziczacym z klasy "
         << getKlasa() << "ktora dziedziczyla z klasy " << getZwierze() << endl;
}
void Karp::Przedstaw()
{
    cout << "Jestem " << getGatunek() << imie << endl;
    cout << "Jestem elementem klasy " << getGatunek() << "dziedziczacym z klasy "
         << getKlasa() << "ktora dziedziczyla z klasy " << getZwierze() << endl;
}
void Lew::Przedstaw()
{
    cout << "Jestem " << getGatunek() << imie << endl;
    cout << "Jestem elementem klasy " << getGatunek() << "dziedziczacym z klasy "
         << getKlasa() << "ktora dziedziczyla z klasy " << getZwierze() << endl;
}
void Slon::Przedstaw()
{
    cout << "Jestem " << getGatunek() << imie << endl;
    cout << "Jestem elementem klasy " << getGatunek() << "dziedziczacym z klasy "
         << getKlasa() << "ktora dziedziczyla z klasy " << getZwierze() << endl;
}
void Pies::Przedstaw()
{
    cout << "Jestem " << getGatunek() << imie << endl;
    cout << "Jestem elementem klasy " << getGatunek() << "dziedziczacym z klasy "
         << getKlasa() << "ktora dziedziczyla z klasy " << getZwierze() << endl;
}
void Kanarek::Przedstaw()
{
    cout << "Jestem " << getGatunek() << imie << endl;
    cout << "Jestem elementem klasy " << getGatunek() << "dziedziczacym z klasy "
         << getKlasa() << "ktora dziedziczyla z klasy " << getZwierze() << endl;
}
void Papuga::Przedstaw()
{
    cout << "Jestem " << getGatunek() << imie << endl;
    cout << "Jestem elementem klasy " << getGatunek() << "dziedziczacym z klasy "
         << getKlasa() << "ktora dziedziczyla z klasy " << getZwierze() << endl;
}
void Golob::Przedstaw()
{
    cout << "Jestem " << getGatunek() << imie << endl;
    cout << "Jestem elementem klasy " << getGatunek() << "dziedziczacym z klasy "
         << getKlasa() << "ktora dziedziczyla z klasy " << getZwierze() << endl;
}

void Zwierze::zyj()
{

    cout << "Zyje i mam sie dobrze." << endl;
}
int main()
{
    Pies *Azor = new Pies("Azor");
    Azor->Przedstaw();
    Azor->zyj();
    delete Azor;
    Lew Zenon("Zenon");
    cout << Zenon.getGatunek();
}