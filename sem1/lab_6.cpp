#include <iostream>


using namespace std;

class element {
  protected:
    double prad;
    double napiecie;
    double moc;
    double czestotliwosc;
    std::string nazwa;
  public:
    element() {nazwa = "element"; czestotliwosc = 1.0; napiecie = prad = moc = 0.0;}
    element(const std::string arg) {nazwa = arg; napiecie = czestotliwosc = 1.0; prad = moc = 0.0;}
    virtual void wymuszenieU(double) = 0;
    virtual void wymuszenieI(double) = 0;
    virtual void wymuszenieUF(double, double) = 0;
    virtual void wymuszenieIF(double, double) = 0;
    friend void obwod(element*, element*); //friend odnosi sie do wszystkiego, prywatne, pub, prot
    void setName(){string arg;cout << "podaj nazwe: "<<endl;cin >> arg;nazwa = arg;}
    string getName(){return nazwa;}
    
};

void obwod(element *e1, element *e2) {
  bool pradMatch = false;
  bool napiecieMatch = false;
  if (e1->prad == e2->prad) {
    pradMatch = true;
  }
  if (e1->napiecie == e2->napiecie) {
    napiecieMatch = true;
  }
  if ((pradMatch && !napiecieMatch) || (!pradMatch && napiecieMatch)) {
    //std::string matchType = (pradMatch)?"prad":"napiecie";
    std::string matchType;
    if (pradMatch) {
      matchType = "prad";
    } else {
      matchType = "napiecie";
    }

    cout << "elementy: " << e1->nazwa.c_str() << " oraz: " << e2->nazwa.c_str() << " maja taki sam: " << matchType.c_str() << endl;
        if (e1->napiecie == e2->napiecie) {
        cout << "###########    sa poloczone rownolegle     ###########" << endl << endl;
        }
        if (e1->prad == e2->prad) {
        cout << "###########    sa polaczone szeregowo      ###########" << endl<<endl;
  }
  } 
  else {
    if (pradMatch && napiecieMatch) {
      cout << "elementy: " << e1->nazwa.c_str() << " oraz: " << e2->nazwa.c_str() << " sa nieokreslone." << endl;
    } else {
      cout << "elementy: " << e1->nazwa.c_str() << " oraz: " << e2->nazwa.c_str() << " sa nie polaczone." << endl;
    }
  }
}

class cewka : public element {
  protected:
    double L;
  public:
    cewka() {nazwa = "cewka"; L = 1.0;}
    cewka(const std::string arg) {nazwa = arg; L = 1.0;}
    cewka(const std::string arg, double argL) {nazwa = arg; L = argL;}
    virtual void wymuszenieU(double); //virtual moze byc a nie musi byc 
    virtual void wymuszenieI(double);
    virtual void wymuszenieUF(double, double);
    virtual void wymuszenieIF(double, double);
};

void cewka::wymuszenieU(double u) {
  napiecie = u;
  if (czestotliwosc > 0.0) {
    prad = u/(6.28*czestotliwosc*L);
  }
}
void cewka::wymuszenieI(double I){
    prad = I;
    if (czestotliwosc > 0.0){
        napiecie = prad * (6.28*czestotliwosc*L);
    }
}
void cewka::wymuszenieIF(double I, double f){
    prad = I;
    czestotliwosc = f;
        napiecie = prad * (6.28*czestotliwosc*L);
    
}
void cewka::wymuszenieUF(double u, double f){
    napiecie = u;
    czestotliwosc = f;
        prad = u/(6.28*czestotliwosc*L);
}

class rezystor : public element{
    protected:
    double Om; //opor
    public:
    rezystor() {nazwa = "rezystor"; Om= 1.0;}
    rezystor(const std::string arg){nazwa = arg; Om = 1.0;}
    rezystor(const std::string arg, double argOm) {nazwa = arg; Om = argOm;}
    virtual void wymuszenieU(double);
    virtual void wymuszenieI(double);
    virtual void wymuszenieUF(double, double){};
    virtual void wymuszenieIF(double, double){};
};
void rezystor::wymuszenieU(double u) {
  napiecie = u;
  if (Om != 0.0) {
    prad = u/Om;
  }
}
void rezystor::wymuszenieI(double I){
    prad = I;
    napiecie = prad * Om;
}


class kondensator : public element{
    protected:
    double C; //pojemnosc
    public:
    kondensator(){nazwa = "kondensator"; C= 1.0;}
    kondensator(const std::string arg){nazwa = arg; C= 1.0;}
    kondensator(const std::string arg, double argC){nazwa = arg; C=argC;}
    virtual void wymuszenieU(double){};
    virtual void wymuszenieI(double){};
    virtual void wymuszenieUF(double, double){};
    virtual void wymuszenieIF(double, double){};
};

int main() {

  element* tab[7];
  tab[0] = new cewka("cewka1");
  tab[1] = new cewka("cewka2", 3.0);
  tab[2] = new cewka("cewka3");
  tab[3] = new cewka("cewka4", 3.2);
  tab[4] = new cewka("cewka5");
  tab[5] = new cewka("cewka6", 3.5);
  tab[0]->wymuszenieU(5);
  tab[1]->wymuszenieU(5);
  tab[2]->wymuszenieU(6);
  tab[3]->wymuszenieU(4);
  tab[4]->wymuszenieU(4);
  tab[5]->wymuszenieU(6);
  obwod(tab[0], tab[1]);
  for(int i=0; i<6;i++){
      for (int k=0; k<6; k++){
          if(i != k)
          obwod(tab[i],tab[k]);
      }
  }

  delete tab[0];
  delete tab[1];
  delete tab[2];
  delete tab[3];
  delete tab[4];
  delete tab[5];
  return 0;
}
