#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

class NazwaKlasy
{
  private:
        string imie;
        string nazwisko;
        int wiek;
        float wzrost;
  public:
        string nr_telefonu;
        char plec;
        void MetodaDane();
        void MetodaPrzedstaw();
        void Szukane(string telefon);
        int osoby[3];
};

void NazwaKlasy::MetodaDane() // metodaDane informacje przypisane do klasy
{
    cout << endl << "Podaj imie: ";
    cin >> imie;
    getchar();


    cout << endl << "Podaj nazwisko: ";
    cin >> nazwisko;
    getchar();

    cout << endl << "Podaj nr telefonu: ";
    cin >> nr_telefonu;
    getchar();

    //cout << endl << "Podaj wiek: ";
    //cin >> wiek;
    //getchar();

    //cout << endl << "Podaj wzrost: ";
    //cin >> wzrost;
    //getchar();

    //cout << endl << "Podaj plec: ";
    //cin >> plec;
    //getchar();
};

void NazwaKlasy::MetodaPrzedstaw() // wyswietlenie informacji przypisanych do
// osob
{
    cout << endl;
    cout << "Witaj" << endl;
    cout << "Nazywam sie " << imie << " " << nazwisko << endl;
    cout << "Nr telefonu " << nr_telefonu << endl;
    //cout << "Wiek " << wiek << endl;
    //cout << "Wzrost " << wzrost << " cm " << endl;
    //cout << "Plec " << plec << endl;
};

void NazwaKlasy::Szukane(string telefon)
{

    if (telefon == nr_telefonu)
    {
        cout << endl;
        cout << "Oto dane tej osoby: " << endl;
        cout << imie << " " << nazwisko << endl;
        //cout << wiek << " lat" << endl;
        //cout << "Wzrost " << wzrost << " cm" << endl;
        //cout << plec << endl;

        cout << "##############" << endl;
        cout << "Czy zapisac dane do pliku? (tak/nie)" << endl;
        string decyzja;
        cin >> decyzja;

        if (decyzja == "tak")
        {
            ofstream strumien("wizytowka.txt", ios::app);
            strumien << imie << " " << nazwisko << endl;
            strumien << wiek << " lat" << endl;
            strumien << "Wzrost " << wzrost << " cm" << endl;
            strumien << plec << endl;
            cout << "Dane zostaly zapisane do folderu wizytowka.txt" << endl;
        }
        else
        {
            cout << "Koniec programu.";
        };
    }
    else
    {
        cout << "Nie ma takiego numeru telefonu w bazie.";
    };
}

    NazwaKlasy osoby[3];
    string telefon;
int main()
{
    for(int i=0; i<3; i++){

        cout << endl;
        cout << "Klasa osoba" << endl;
        osoby[i].MetodaDane();

    };
    for (int j=0; j<3; j++){

        osoby[j].MetodaPrzedstaw();
    };

    cout << "Podaj numer szukanej osoby: " ;
    cin >> telefon;

    for(int i=0; i<3; i++){

        osoby[i].Szukane(telefon);

    };


    getchar();
    return 0;
};



