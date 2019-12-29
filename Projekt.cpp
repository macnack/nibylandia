#include <iostream>
#include <fstream>
#include <string>
#include <cstring>


/*14. C++ wczytanie n liczb do tablicy z pliku, średnia arytmetyczna, oraz największa liczba
Program wczytuje od użytkownika liczbę tworzy tablice i wczytuje do niej tyle liczb ile podał w zmiennej n.*/
using namespace std;
char* pch;
ifstream plik;

class A {

    double liczba;
    static double suma, max, rozmiar;

public:
    //double getliczba() { return liczba; }
    A() { ; }
    void wyswietl() { cout << liczba; }
    friend void wczytaj_liczby(A& obiekt){
        obiekt.liczba = stod(pch);
        A::suma += obiekt.liczba;
        A::rozmiar++;
    if (A::max < obiekt.liczba)
        A::max = obiekt.liczba;
    }
    static void przedstaw()
    {
    cout << "Wartosc maksymalna w tablicy wynosi: " << A::max << endl
         << "Srednia wynosi: " << A::suma / A::rozmiar << endl;
    //cout << "Suma wynosi: " << A::suma << endl;
    }
};

double A::suma;
double A::rozmiar;
double A::max = 0;

bool wczytaj_plik(string nazwa)
{
    plik.open(nazwa.c_str());
    if (plik.good() == 0)
        return 0;

    cout << "Wczytano plik: '" << nazwa << "'" << endl;
    return 1;
}

int main()
{
    int n = 20, i = 0;
    string nazwa = "nazwa_pliku.txt", tmp;
    cout << "Witaj uzytkowniku! " << endl
         << "Podaj nazwe pliku: " << endl;
    getline(cin, nazwa);
    if (!wczytaj_plik(nazwa)) {
        do {
            cout << endl
                 << "######################" << endl
                 << "Podaj nazwe ponownie: " << endl;
            getline(cin,nazwa);
        } while (!wczytaj_plik(nazwa));
    }
    cout << "Podaj liczbe: " << endl;
    cin >> n;

    A* tablica = new A[n];
    while (!plik.eof()) {
        getline(plik, tmp);
        char str[tmp.size() + 1];
        strcpy(str, tmp.c_str());
        pch = strtok(str, "\t,; \n");
        if (i != n) {
            while (pch != NULL) {
                wczytaj_liczby(tablica[i]);
                //cout << tablica[i].getliczba() << endl;
                i++;
                pch = strtok(NULL, "\t,; \n");
                if (i == n) {
                    break;
                };
            }
        }
    }
    A::przedstaw();
    plik.close();
    delete tablica;
}
