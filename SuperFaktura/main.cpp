#include <iostream>
#include <vector>

enum Vat
{
    A = 23,
    B = 8,
    C = 0
};
class Item
{
private:
    std::string nazwa;
    double netto;
    Vat stawka;
    int il;

public:
    Item(std::string arg_nazwa, double arg_netto, Vat arg_stawka, int arg_il);
};
class Invoice
{
private:
    float w_nip_;
    float n_nip_;
    std::vector<Item> items;

public:
    void add_item(Item it);
    Invoice(float w_nip, float n_nip);
};
Item::Item(std::string arg_nazwa, double arg_netto, Vat arg_stawka, int arg_il)
{
    nazwa = arg_nazwa;
    netto = arg_netto;
    stawka = arg_stawka;
    il = arg_il;
}
Invoice::Invoice(float w_nip, float n_nip)
{
    w_nip_ = w_nip;
    n_nip_ = n_nip;
}

int main()
{
    Invoice inv(7770003699, 1234567890);
    //inv.add_item(Item("Sruba M3", 0.37, 'A', 100));
    //inv.add_item(Item("Wiertlo 2 mm", 2.54, 'B', 2));
    //cout << inv << endl;
    return 0;
}
