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
    void wczytaj_liczba(char* zmienna)
    {
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
A* stworz_tab(int& podany_n)
{
    if (podany_n > 1000) {
        podany_n = 1000;
        cout << "Przekroczono maksymalny rozmiar tablicy" << endl
             << "Program sam przypisze maksymalna wartosc"<< endl
             << endl;
    }
    return new A[podany_n];
}
void obsluga_zapisu(char& separator)
{
    cout << "Zapis mozna dokonać za pomocą nowego separatora," << endl
         << "program zapisuje liczby ktore zostaly pobrane wczesniej" << endl
         << "[1] - separator tabulator " << endl
         << "[2] - separator przecinek " << endl
         << "[3] - separator srednik " << endl
         << "[4] - separator spacja " << endl
         << "[5] - separator znaku nowej linii" << endl;
    char c_wybor[3];
    do {
        cin >> c_wybor;
    } while (!isdigit(c_wybor[0]));
    int wybor = c_wybor[0] - 48;
    switch (wybor) {
    case 1:
        separator = '\t';
        break;
    case 2:
        separator = ',';
        break;
    case 3:
        separator = ';';
        break;
    case 4:
        separator = ' ';
        break;
    case 5:
        separator = '\n';
        break;
    }
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
    int n;
    cout << "Podaj liczbe: " << endl;
    cin >> n;
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
    if (Active == true) {
        A* aktualny_rekord;
        int x = A::getRozmiar();
        aktualny_rekord = &tablica[0];
        while (!plik.eof()) {
            string tmp;
            char* pch;
            //int x = A::getRozmiar();
            getline(plik, tmp);
            char str[tmp.size() + 1];
            strcpy(str, tmp.c_str());
            pch = strtok(str, "\t,; \n");
            if (x != n) {
                while (pch != NULL) {
                    aktualny_rekord->wczytaj_liczba(pch);
                    //cout << aktualny_rekord->getliczba() << endl;
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
        cout << "Tutaj";
        cout <<'\n' <<  A::getRozmiar() << "###" << n; 
        cout << "Zapis do pliku [t/n] ";
        cin.ignore();
        char znak = cin.get();
        if (znak == 't') {
            char separator;
            obsluga_zapisu(separator);
            cout << endl;
            if (separator == '\n') {
                for (int i = 0; i < n; i++) {
                    cout << tablica[i].getliczba() << '\n';
                }
            }
            else {
                cout << "Podaj liczbe kolumn : ";
                int liczba_kolumn;
                cin >> liczba_kolumn;
                if (liczba_kolumn == 0) {
                    for (int i = 0; i < x; i++) {
                        cout << tablica[i].getliczba() << separator;
                    }
                }
                else {
                    for (int i = 1; i <= n; i++) {
                        if (((i) % liczba_kolumn == 0) || (i == n))
                            cout << tablica[i - 1].getliczba() << endl;
                        else {
                            cout << tablica[i - 1].getliczba() << separator;
                        }
                    }
                }
            }
        }
        delete[] tablica;
    }
    cout << endl;
    cout << "Koniec programu." << endl;
    return 0;
}