#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

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
    void
    set_stawka(const char &stawka_b);
    Item(std::string arg_nazwa, double arg_netto, char arg_stawka, int arg_il);
    friend std::ostream &operator<<(std::ostream &out, const std::vector<Item> items);
};
class Invoice
{
private:
    long w_nip_;
    long n_nip_;
    std::vector<Item> items;

public:
    void add_item(Item it);
    long sprzedawca() const;
    long nabywca() const;
    Invoice();
    Invoice(long w_nip, long n_nip);
    bool add(const Invoice &other);
    bool add_items(const std::vector<Item> other_items);
    //Invoice operator+(const Invoice &r1);
    friend std::ostream &operator<<(std::ostream &out, const std::vector<Item> items);
    friend std::ostream &operator<<(std::ostream &out, const Invoice &el);
};
bool Invoice::add(const Invoice &other)
{
    if ((sprzedawca() == other.sprzedawca()) && (nabywca() == other.nabywca()))
    {
        std::vector<Item> o_items = other.items;
        for (Item &ot : o_items)
        {
            items.push_back(ot);
        }
        return true;
    }
    return false;
}
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
long Invoice::sprzedawca() const
{
    return w_nip_;
}
long Invoice::nabywca() const
{
    return n_nip_;
}
Item::Item(std::string arg_nazwa, double arg_netto, char arg_stawka, int arg_il)
{
    nazwa = arg_nazwa;
    netto = arg_netto;
    stawka_ = arg_stawka;
    set_stawka(stawka_);
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
    double tmp_brutto;
    double tmp_netto;
    for (unsigned int i = 0; i < items.size(); i++)
    {
        out.width(3);
        out << std::left << std::to_string(i + 1) + ".";
        out.width(13);
        out << std::left << items[i].nazwa;
        out.width(4);
        std::string str = std::to_string(items[i].netto);
        str.erase(str.find_last_not_of('0') + 1, std::string::npos);
        out << std::internal << "| " + str;
        out.width(3);
        out << items[i].stawka_ << " |";
        out.width(5);
        out << std::internal << std::to_string(items[i].il) << " |";
        out.width(5);
        tmp_netto = items[i].netto * items[i].il * (items[i].stawka / 100.0 + 1);
        tmp_netto = round(tmp_brutto * 100.0) / 100.0;
        out << std::internal << items[i].netto * items[i].il << " |";
        out.width(8);
        out << std::setprecision(4);
        tmp_brutto = items[i].netto * items[i].il * (items[i].stawka / 100.0 + 1);
        tmp_brutto = round(tmp_brutto * 100.0) / 100.0;
        out << std::internal << tmp_brutto;
        out << std::endl;
    }
    tmp_brutto = 0;
    tmp_netto = 0;
    for (Item et : items)
    {
        tmp_brutto += et.netto * et.il * (et.stawka + 100) / 100;
        tmp_netto += et.netto * et.il;
    }
    out << std::setfill('-') << std::setw(45) << "RAZEM" << std::setfill('-') << std::setw(5) << "\n";
    tmp_brutto = round(tmp_brutto * 100.0) / 100.0;
    tmp_netto = round(tmp_netto * 100.0) / 100.0;
    std::string str1 = std::to_string(tmp_brutto);
    std::string str2 = std::to_string(tmp_netto);
    str1.erase(str1.find_last_not_of('0') + 1, std::string::npos);
    str2.erase(str2.find_last_not_of('0') + 1, std::string::npos);
    out << std::setfill(' ');
    out << std::setw(49) << std::right << str2 + " | " + str1 << std::endl;
    return out;
}
std::ostream &operator<<(std::ostream &out, const Invoice &el)
{
    out << std::string(19, '-') << "FAKTURA VAT" << std::string(19, '-') << std::endl;
    out << std::string(49, '=') << std::endl;
    out << std::endl;
    out.width(24);
    out << std::left << "Sprzedawca: " + std::to_string(el.w_nip_);
    out.width(25);
    out << std::right << "Nabywca: " + std::to_string(el.n_nip_);
    out << std::endl;
    out.width(18);
    out << "";
    out.width(7);
    out << std::left << "c.j. VAT";
    out.width(6);
    out << std::internal << "il.";
    out.width(8);
    out << std::internal << "netto";
    out.width(8);
    out << std::internal << "brutto";
    out << std::endl;
    out << el.items;
    out << std::endl;

    return out;
}
int main()
{
    Invoice inv(7770003699, 1234567890);
    inv.add_item(Item("Sruba M3", 0.37, 'A', 100));
    inv.add_item(Item("Wiertlo 2 mm", 2.54, 'B', 2));
    std::cout << inv << std::endl;
    Invoice inv2(7770003699, 1234567890);
    inv2.add_item(Item("Sruba M3", 0.37, 'A', 250));
    inv2.add_item(Item("Wiertlo 2 mm", 2.54, 'B', 10));
    inv.add(inv2);
    std::cout << inv << std::endl;

    return 0;
}
