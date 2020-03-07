14. C++ wczytanie n liczb do tablicy z pliku, średnia arytmetyczna,
oraz największa liczba. Program wczytuje od użytkownika liczbę tworzy tablice i 
wczytuje do niej tyle liczb ile podał w zmiennej n.

Opis programu:
Program wczytuje plik, następnie zapisuje jego wiersze do stringa.
Wiersze w zaleznosci od formatu są ograniczone za pomoca separatora
(np.bialy znak, przecinek, srednik).Nastepnie kopiuje stringa do tablicy
znakow char, aby za pomoca funkcji moc oddzielic liczby i przypisac
je do obiektu w klasie.Liczby sa sumowane oraz dzielone przez ich ilosc,
aby wyliczyc srednia.Podczas tej metody, program sprawdza czy liczba jest
wieksza od poprzedniej, jesli tak przypisuje ją jako wartość maksymalna.

Program jest zabezpieczony przed błedami takimi jak:
-nieprawidlowa nazwa pliku,
-wpisanie liter gdy program oczekuje zmiennej int,
-nieprawidlowy rozmiaru tablicy (bad_array_new_length),

Instrukcja:
Uzytkownik musi wpisac prawidlowa nazwe pliku, nastepnie podac rozmiar
tablicy (z przedziału [0,1000]), jeśli użytkownik chce zapisać wybrany przedzial
do nowego pliku wciska 't' nastepnie program prosi o wybranie separatora liczb,
w zaleznosci od separatora program prosi o podanie liczby kolumn. Jesli uzytkownik
nie chce zapisywac programu wciska 'n'.

Do archiwum dołaczyłem przykladowe pliki tekstowe i csv 
