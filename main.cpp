#include <iostream>
#include <ostream>
#include <string>
#include <cstdio>
#include "hist.h"
#include "MultiZbior.h"
#include "Multizbiortest.h"
using namespace std;

int main()
{
    Multizbiortest t; //testy wykonywane przez metody klasy testowej Multizbiortest
    t.testdodawanieusuwanie();
    t.testlicznosci();
    t.testplus();
    t.testprzeciecia();
    t.testrownosci();
    t.testdodawanieusuwanie2();
    t.testlicznosci2();
    t.testplus2();
    t.testprzeciecia2();
    t.testrownosci2();
    return 0;
}
