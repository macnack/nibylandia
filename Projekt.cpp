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
    static double suma, max;
    static int rozmiar;

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
    static int getRozmiar(){
        return rozmiar;
    }
};

double A::suma;
double A::max = 0;
int A::rozmiar;

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
    int i = 0;
    string nazwa = "nazwa_pliku.txt";
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
    int n;
    cout << "Podaj liczbe: " << endl;
    cin >> n;
    if( n > 1000){
        cout << "Rozmiar tablicy przekroczył maksymalna wartosc."
             << endl;
        cin >> n;
    }
    A *tablica;
    try
    {
        tablica = new A[n];
    }
    catch(const std::exception& e)
    {
        cout << "Rozmiar tablicy jest ujemny " << endl
             << e.what() << endl;
    }
    

    //https://en.cppreference.com/w/cpp/memory/new/bad_array_new_length
    while (!plik.eof()) {
        string tmp;
        int x = A::getRozmiar();
        getline(plik, tmp);
        char str[tmp.size() + 1];
        strcpy(str, tmp.c_str());
        pch = strtok(str, "\t,; \n");
        if (x != n) {
            while (pch != NULL) {
                wczytaj_liczby(tablica[x]);
                //cout << tablica[i].getliczba() << endl;
                pch = strtok(NULL, "\t,; \n");
                if (x == n) {
                    plik.close();
                    break;
                };
            }
        }
    }
    //dodac wcisnij q lub koniec aby zakonczyc progam.
    A::przedstaw();
    delete tablica;
    cin.get();
}
