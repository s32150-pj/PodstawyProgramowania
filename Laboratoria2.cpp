// Laboratoria2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    int ilosc_osob=23;
    int ilosc_kawalkow=100;

    int ilosc_kawalkow_na_osobe;
    int reszta;

    ilosc_kawalkow_na_osobe = ilosc_kawalkow / ilosc_osob;
    reszta = ilosc_kawalkow - (ilosc_kawalkow_na_osobe * ilosc_osob);

    cout << " Kazda osoba otrzyma " << ilosc_kawalkow_na_osobe << " kawalkow pizzy." << endl;
    cout << "Dla organizatora zostanie " << reszta << " kawalkow pizzy." << endl;

}

