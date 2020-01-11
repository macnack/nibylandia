#include <iostream>
#include <fstream>
#include <string>
#include <cstring>


/*14. C++ wczytanie n liczb do tablicy z pliku, średnia arytmetyczna, oraz największa liczba
Program wczytuje od użytkownika liczbę tworzy tablice i wczytuje do niej tyle liczb ile podał w zmiennej n.*/
using namespace std;
class A {

    double liczba;
    static double suma, max;
    static int rozmiar;

public:
    //double getliczba() { return liczba; }
    A() { ; }
    void wyswietl() { cout << liczba; }
    friend void wczytaj_liczby(A& obiekt, char* liczba){
        obiekt.liczba = stod(liczba);
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
double A::max;
int A::rozmiar;
ifstream plik;

bool wczytaj_plik(string nazwa)
{
    plik.open(nazwa.c_str());
    if (plik.good() == 0)
        return 0;
    cout << "Wczytano plik: '" << nazwa << "'" << endl;
    return 1;
}
void ClearScreen(){
    cout << string(100, '\n');
}

int main()
{
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
        cout << endl
             << "Rozmiar tablicy jest ujemny " << endl
             << "Error: " << e.what() << endl;
    }
    //https://en.cppreference.com/w/cpp/memory/new/bad_array_new_length
    while (!plik.eof()) {
        string tmp;
        char* pch;
        int x = A::getRozmiar();
        getline(plik, tmp);
        char str[tmp.size() + 1];
        strcpy(str, tmp.c_str());
        pch = strtok(str, "\t,; \n");
        if (x != n) {
            while (pch != NULL) {
                wczytaj_liczby(tablica[x],pch);
                //cout << tablica[x].getliczba() << endl;
                pch = strtok(NULL, "\t,; \n");
                if (x == n) {
                    plik.close();
                    break;
                };
            }
        }
    }
    ClearScreen();
    A::przedstaw();
    cout << "Zapis do pliku [t/n]" << endl;
    string znak;
    cin >> znak;
    if (znak == "t")
    {
        cout << "Zapisuje" << endl;
    }
    cout << "Koniec programu." << endl;

    delete[] tablica;
}
