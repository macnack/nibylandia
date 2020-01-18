#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;
class A {

    double liczba;
    static double suma, max;
    static int rozmiar;

public:
    double getliczba() { return liczba; }
    A() { ; }
    void wczytaj_liczba(char* zmienna){
        liczba = stod(zmienna);
        A::suma += liczba;
        A::rozmiar++;
        if (A::max < liczba)
            A::max = liczba;
    }
    static void przedstaw()
    {
        cout << "Wartosc maksymalna w tablicy wynosi: " << A::max << endl
             << "Srednia wynosi: " << A::suma / A::rozmiar << endl;
        //cout << "Suma wynosi: " << A::suma << endl;
    }
    static int getRozmiar()
    {
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
void ClearScreen()
{
    cout << string(100, '\n');
}
A* stworz_tab(int &podany_n){
    if(podany_n>1000){
        podany_n = 1000;
    }
    return new A[podany_n];
}
int main()
{
    bool Active = true;
    string nazwa = "xyz.txt";
    cout << "Witaj uzytkowniku! " << endl
         << "Podaj nazwe pliku: " << endl;
    //getline(cin, nazwa);
    if (!wczytaj_plik(nazwa)) {
        do {
            cout << endl
                 << "######################" << endl
                 << "Podaj nazwe ponownie: " << endl;
            getline(cin, nazwa);
        } while (!wczytaj_plik(nazwa));
    }
    int n=20;
    cout << "Podaj liczbe: " << endl;
    //cin >> n;
    ClearScreen();
    A* tablica;
    try {
        tablica = stworz_tab(n);
    }
    catch (const std::exception& e) {
        cout << endl
             << "Rozmiar tablicy jest ujemny " << endl
             << "Error: " << e.what() << endl;
        Active = false;
    }
    if(Active == true){
    A *aktualny_rekord;
    aktualny_rekord = &tablica[0];
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
                aktualny_rekord->wczytaj_liczba(pch);
                cout << aktualny_rekord->getliczba() << endl;
                aktualny_rekord++;
                //tablica[x].wczytaj_liczba(pch);
                //cout << tablica[x].getliczba() << endl;
                pch = strtok(NULL, "\t,; \n");
                if (x == n) {
                    plik.close();
                    break;
                };
            }
        }

    }
    A::przedstaw();
    cout << "Zapis do pliku [t/n] ";
    cin.ignore();
    char znak ='t';//= cin.get();
    if (znak == 't') {
        cout << "Zapisuje" << endl;
        int i =0;
        while(i != n){
            cout << endl;
            for(int j=0;j<5;j++){
                cout << tablica[i].getliczba() << " ";
                i++;
            }
        }     
    }
    delete[] tablica;
    }
    cout << "Koniec programu." << endl;
    return 0;
}
