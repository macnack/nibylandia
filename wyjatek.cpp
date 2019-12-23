#include <iostream>
using namespace std;

class wyjatek {
    double numer;
    string opis;
    static double id_number; 
    public: 
    string getOpis(){ return opis;}
    double getNumer(){ return numer;}
    wyjatek(double argNumer, string argOpis){ numer = argNumer; opis = argOpis;}
	~wyjatek(){;}
    

};
class stosik{
    double x, y, z;
    public:
    stosik(double argx, double argy);
    double hmean(double a, double b){
    if (a == -b)
        throw "Niepoprawne argumenty funkcji hmean(): a = -b nie jest dozwolone";
    return 2.0 * a *b /(a+b);
}

};
stosik::stosik(double argx, double argy){
    x = argx;
    y = argy;
}

int main(){
    wyjatek *blad = new wyjatek( 0 , "Error ");
    cout << blad->getOpis() << " " << blad->getNumer() << endl;
    wyjatek *blad = new wyjatek[];
     
}