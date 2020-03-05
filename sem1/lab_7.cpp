#include <iostream>

using namespace std;

class Punkt3D {
  public:
    float x,y,z;
    Punkt3D() {x=y=z=0.0f;}
    Punkt3D operator+(int);
};

Punkt3D Punkt3D::operator+(int arg){
  Punkt3D tmp;
  tmp.x = x+(float)arg;
  tmp.y = y+(float)arg;
  tmp.z = z+(float)arg;
  return tmp;
}
Punkt3D operator+(int arg, Punkt3D& s){
    Punkt3D tmp;
    tmp.x = s.x+(float)arg;
    tmp.y = s.y+(float)arg;
    tmp.z = s.z+(float)arg;
    return tmp;
}

ostream& operator<< (ostream &wyjscie, Punkt3D& s)
{
  wyjscie<<"["<<s.x<<", "<<s.y<<", "<<s.z<<"]"<<endl;
  return wyjscie;
}
/*ostream& operator<< (ostream &wyjscie, Punkt3D *s)
{
  wyjscie<<"["<<s->x<<", "<<s->y<<", "<<s->z<<"]"<<endl;
  return wyjscie;
}*/
class wektor {
  public:
    float dx,dy,dz;
    wektor() {dx=dy=dz=0.0f;}
};

ostream& operator<< (ostream &wyjscie, wektor &s)        
{
  wyjscie<<"["<<s.dx<<", "<<s.dy<<", "<<s.dz<<"]"<<endl;
  return wyjscie;
}

Punkt3D operator+(Punkt3D& s, wektor d)
{
    Punkt3D tmp;
    tmp.x = s.x + d.dx;
    tmp.y = s.y + d.dy;
    tmp.z = s.z + d.dz;
    return tmp;
}
Punkt3D operator+(wektor& d, Punkt3D& s)
{
    Punkt3D tmp;
    tmp.x = s.x + d.dx;
    tmp.y = s.y + d.dy;
    tmp.z = s.z + d.dz;
    return tmp;
}
wektor operator*(wektor& s1, wektor& s2)
{
    wektor tmp;
    tmp.dx =   (s1.dy*s2.dz) - (s1.dz*s2.dy) ;
    tmp.dy = -((s1.dx*s2.dz) - (s1.dz*s2.dx));
    tmp.dz =   (s1.dx*s2.dy) - (s1.dy*s2.dx) ;
    return tmp;
}


int main() {
  Punkt3D a;
  {a.x = 3.0f; a.y = 5.0f; a.z = 0.0f;}
  Punkt3D b;
  {b.x = 2.0f; b.y = -2.0f; b.z = 3.0f;}
  wektor c;
  {c.dx = 2.0f; c.dy = 5.0f; c.dz = -1.0f;} 
  wektor d;
  {d.dx = -2.0f; d.dy = 4.0f; d.dz = -6.0f;}
  cout << "Punkt A: " << a << "Punkt B: " << b;
  cout << "Wektor c: "<< c << "wektor d: "<< d;
  Punkt3D x = a+c;
  cout << "Translacja punktu A o wektor c: " << x;
  wektor iloczyn = d*c;
  cout << "Iloczyn wektorów c i d: " << iloczyn;
  x = b + iloczyn;
  cout << "Translacja punktu B o iloczyn wektorowy c i d: "<<x;
  x=x+3;
  cout << "+3: " << x;
  /*Punkt3D *z = new Punkt3D;
  z->x = 2;
  z->y = 4;
  cout << z;*/
  
}
