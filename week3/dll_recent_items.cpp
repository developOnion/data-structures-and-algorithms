#include <iostream>

#include "../header/DoubleLinkList.hpp"

void add(DoubleLinkList<int> &tray, int val);
void remove(DoubleLinkList<int> &tray);

int main(void)
{
    DoubleLinkList<int> tray;
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

void add(DoubleLinkList<int> &tray, int val)
{
    tray.unshift(val);
}

void remove(DoubleLinkList<int> &tray)
{
    if (tray.size() < 0)
        return;

    tray.shift();
}