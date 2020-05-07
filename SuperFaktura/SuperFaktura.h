#ifndef SUPERFAKTURA_H
#define SUPERFAKTURA_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>

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
    //bool operator<(const Item &r2);
    bool add_il(int ot);
    std::string get_nazwa() { return nazwa; }
    int get_il() { return il; }
    void set_stawka(const char &stawka_b);
    Item(std::string arg_nazwa, double arg_netto, char arg_stawka, int arg_il);
    friend class Invoice;
    friend std::ostream &operator<<(std::ostream &out, const std::vector<Item> items);
};
class Invoice
{
private:
    long sprzedawca_;
    long nabywca_;
    std::vector<Item> items;

public:
    bool add(const Invoice &other);
    bool add_items(const std::vector<Item> other_items);
    long nabywca() const;
    long sprzedawca() const;
    void add_item(Item it);
    Invoice(long w_nip, long n_nip);
    Invoice(){};
    friend std::ostream &operator<<(std::ostream &out, const std::vector<Item> items);
    friend std::ostream &operator<<(std::ostream &out, const Invoice &el);
};

#endif // SUPERFAKTURA_H
