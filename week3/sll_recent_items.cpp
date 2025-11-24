#include <iostream>

#include "../header/SingleLinkList.hpp"

void add(SingleLinkList<int> &tray, int val);
void remove(SingleLinkList<int> &tray);

int main(void)
{
    SingleLinkList<int> tray;
    add(tray, 1);
    tray.display();
    add(tray, 2);
    tray.display();
    add(tray, 3);
    tray.display();
    add(tray, 4);
    tray.display();

    std::cout << "\n";

    remove(tray);
    tray.display();
    remove(tray);
    tray.display();
    remove(tray);
    tray.display();
    remove(tray);
    tray.display();
}

void add(SingleLinkList<int> &tray, int val)
{
    tray.unshift(val);
}

void remove(SingleLinkList<int> &tray)
{
    if (tray.size() < 0)
        return;

    tray.shift();
}