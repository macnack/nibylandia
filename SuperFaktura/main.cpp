#include "SuperFaktura.h"

int main()
{
    Invoice inv(7770003699, 1234567890);
    inv.add_item(Item("Sruba M3", 0.37, 'A', 100));
    inv.add_item(Item("Wiertlo 2 mm", 2.54, 'B', 2));
    std::cout << inv << std::endl;
    Invoice inv2(7770003699, 1234567890);
    inv2.add_item(Item("Sruba M3", 0.37, 'A', 250));
    inv2.add_item(Item("Wiertlo 2 mm", 2.54, 'B', 10));
    std::cout << inv2 << std::endl;
    inv.add(inv2);
    std::cout << inv << std::endl;
    return 0;
}
