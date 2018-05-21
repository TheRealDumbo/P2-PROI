#ifndef MULTIZBIORTEST_H
#define MULTIZBIORTEST_H
#endif
#include <iostream>
#include <ostream>
#include <string>
#include <cstdio>

class Multizbiortest //klasa testujaca dzialanie poszczegolnych metod szabonu Multizbior
{
public:
    void testdodawanieusuwanie(); //nazwy dosyc samo wyjasniajace: licznosc- SprawdzCzyNalezy(), IleDanegoElementu(), IleWszystkich(); plus - operator + etc.
    void testlicznosci();
    void testplus();
    void testprzeciecia();
    void testrownosci();
    void testdodawanieusuwanie2(); //indeks "2" oznacza testy tych samych metod dla klasy zdefiniowanej przez uzytkownika, w tym przypadku hist
    void testlicznosci2();
    void testplus2();
    void testprzeciecia2();
    void testrownosci2();
};
