#include<iostream>
#include<fstream>
#include<stdlib.h>
//hej
using namespace std;
// whats upppp 
class osoba
{
public:

    osoba();
    osoba(string argimie);
    osoba(string argimie, string argnazwisko);
    osoba(string argimie, string argnazwisko, int argwiek);
    osoba(int argwiek, string argimie, string argnazwisko);
    ~osoba();
    static void info();
    void przedstaw();
    static int aktualnie_w_systemie;
    static int id_ostatnie;

protected:


private:

    int wiek;
    string imie;
    string nazwisko;
    int id;

};
int osoba::aktualnie_w_systemie;
int osoba::id_ostatnie;

void osoba::przedstaw()
{
    cout <<"Imie: " << osoba::imie <<endl<<
       "Nazwisko: " << osoba::nazwisko << endl<< 
           "Wiek: " << osoba::wiek << endl <<
             "ID: " << osoba::id <<endl;
}
osoba::osoba()
{
    aktualnie_w_systemie++;
    id_ostatnie++;
    id=id_ostatnie;
}

osoba::osoba(string argimie)
{
    aktualnie_w_systemie++;
    id_ostatnie++;
    id=id_ostatnie;
    imie = argimie;
}
osoba::osoba(string argimie, string argnazwisko)
{
    aktualnie_w_systemie++;
    id_ostatnie++;
    id=id_ostatnie;
    nazwisko = argnazwisko;
    imie = argimie;
}
osoba::osoba(string argimie, string argnazwisko, int argwiek)
{
    aktualnie_w_systemie++;
    id_ostatnie++;
    id=id_ostatnie;
    imie = argimie;
    nazwisko = argnazwisko;
    wiek = argwiek;
}
osoba::osoba(int argwiek, string argimie, string argnazwisko)
{
    aktualnie_w_systemie++;
    id_ostatnie++;
    id=id_ostatnie;
    wiek = argwiek;
    imie = argimie;
    nazwisko = argnazwisko;
}
osoba::~osoba()
{
    cout << "Jestem w destruktorze !" << endl;
    aktualnie_w_systemie--;
}

void osoba::info()
{
    cout<<"Dotychczas utworzono: "<< osoba::id_ostatnie <<  " obiektow"<<endl;
    cout<<"Obecnie w systemie mamy: "<< osoba::aktualnie_w_systemie<< " obiektow" <<endl;
}

int main()
{
    string temp;
    ifstream wejscie("plik.txt");
    getline(wejscie,temp);
    osoba::id_ostatnie=atoi(temp.c_str());
    osoba::aktualnie_w_systemie=0;
    // tworzymy osoby
    osoba *person1;
    person1 = new osoba(); // zasada dzialania wskaznika i konstruktora
    osoba *person2;
    person2 = new osoba("January");
    osoba *person3;
    person3 = new osoba("Janusz", "Dyniec");
    osoba *person4;
    person4 = new osoba("Dawid", "Romaniec", 20 );
    osoba person5( 22, "Andrzej", "Strzelba");  // zasada dzialania konstruktora
    osoba::info();
    delete person1; // zasada dzialania destruktora wskaznika
    osoba::info();
    person2->przedstaw();
    person5.~osoba(); // zasada dzialania destruktora
    osoba::info();
    cin.get();



    ofstream wyjscie("plik.txt",ios::trunc);
    wyjscie << osoba::id_ostatnie;
    return 0;
}
