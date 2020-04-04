#include <iostream>
#include <vector>
#include <iomanip>

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
    char stawka_;
    Vat stawka;
    int il;

public:
    void set_stawka(const char &stawka_b);
    Item(std::string arg_nazwa, double arg_netto, char arg_stawka, int arg_il);
};
class Invoice
{
private:
    long w_nip_;
    long n_nip_;
    std::vector<Item> items;

public:
    void add_item(Item it);
    Invoice(long w_nip, long n_nip);
    friend std::ostream &operator<<(std::ostream &ouy, const std::vector<Item> items);
    friend std::ostream &operator<<(std::ostream &out, const Invoice &el);
};
void Item::set_stawka(const char &stawka_)
{
    switch (stawka_)
    {
    case 'A':
        stawka = Vat::A;
        break;
    case 'B':
        stawka = Vat::B;
        break;
    case 'C':
        stawka = Vat::C;
        break;
    }
}
Item::Item(std::string arg_nazwa, double arg_netto, char arg_stawka, int arg_il)
{
    nazwa = arg_nazwa;
    netto = arg_netto;
    set_stawka(arg_stawka);
    il = arg_il;
}
Invoice::Invoice(long w_nip, long n_nip)
{
    w_nip_ = w_nip;
    n_nip_ = n_nip;
}
void Invoice::add_item(Item it)
{
    items.push_back(it);
}
std::ostream &operator<<(std::ostream &out, const std::vector<Item> items)
{
    for (unsigned int i = 0; i < items.size(); i++)
    {
        
    }

    return out;
}
std::ostream &operator<<(std::ostream &out, const Invoice &el)
{
    out << std::setw(25) << "+";
    out << std::string(19, '-') << "FAKTURA VAT" << std::string(19, '-') << std::endl;
    out << std::string(49, '=') << std::endl;
    out << std::endl;
    out.width(24);
    out << std::left << "Nabywca: " + std::to_string(el.n_nip_);
    out.width(25);
    out << std::right << "Sprzedawca: " + std::to_string(el.w_nip_);
    out << std::endl;
    return out;
}

int main()
{
    Invoice inv(7770003699, 1234567890);
    inv.add_item(Item("Sruba M3", 0.37, 'A', 100));
    inv.add_item(Item("Wiertlo 2 mm", 2.54, 'B', 2));
    std::cout << inv << std::endl;
    std::cout << std::left << std::setw(25) << "Column 1" << std::setw(25) << "Column 2" << std::endl;
    //std::cout.width(name_wid);
    return 0;
}
