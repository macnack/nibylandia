#include <iostream>
using namespace std;
class Wyjatek
{
private:
	int numer;
	string opis;

public:
	Wyjatek(int argNumer, string argOpis)
	{
		numer = argNumer;
		opis = argOpis;
	}
	~Wyjatek() { cout << " Jestem w destruktorze" << endl; }
	string getOpis() { return opis; }
	int getNumer() { return numer; }
};

class Stos
{
private:
	int *tablica;

public:
	Stos() { tablica = new int[10]; };
	~Stos() { delete[] tablica; };
	void push(int a, int i)
	{
		//wpisz a do komorki "i" tablicy
		//jezeli wychodzisz poza zakres rzuc wyjatkiem
		if (i > 10)
		{
			Wyjatek *wyj = new Wyjatek(0, "Jestesmy poza zakresem");
			throw wyj;
		}
		else
		{
			tablica[i - 1] = a;
		}
	};
	int pop(int i)
	{
		//zwroc "i"-ty element tablicy
		//jezeli wychodzisz poza zakres rzuc wyjatkiem
		if (i > 10)
		{
			Wyjatek *wyja = new Wyjatek(1, "Wychodzisz poza zakres tablicy");
			throw wyja;
		}
		else
		{
			return tablica[i + 1];
		}
	}
};

class Symulacja
{
	Stos *stosik;

public:
	Symulacja()
	{
		cout << "Konstruktor symulacja " << endl;
		stosik = new Stos();
	};
	~Symulacja()
	{
		cout << "Destruktor symulacja" << endl;
		delete stosik;
	}
	void sim();
};

void Symulacja::sim()
{
	// napisz petle wypelniajac tablice (push) obejmij to klauzula "try" i celowo przekrocz zakres
	// zlap wyjatek, wyswietl numer bledu i jego opis

	// napisz petle pobierajaca "i"-ty element tablicy (pop) obejmij to klauzula "try" i celowo przekrocz zakres
	// zlap wyjatek, wyswietl numer bledu i jego opis
	for (int i = 0; i < 17; ++i)
	{
		try
		{
			stosik->push(5, i);
		}
		catch (Wyjatek *w)
		{
			if (w != NULL)
			{
				cout << w->getOpis() << " nr: " << w->getNumer() << endl;
			}
			delete w;
		}
	}
}

int main()
{
	Symulacja sm;
	Stos tab;
	sm.sim();
}