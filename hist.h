#ifndef HIST_H
#define HIST_H
#endif // HIST_H
#include <iostream>
#include <ostream>
#include <string>
#include <cstdio>
class hist //klasa zdefiniowana przez uzytkownika, 2 pola i konstruktor + przeciazone operatory wymagane w metodach szablonu, probowalem uzyc klasy z poprzedniego projektu, nazwa zostala
{
public:
    hist(double a, double b);
    hist();
    friend bool operator==(hist a, hist b);
    friend bool operator<(hist a, hist b);
    friend bool operator>(hist a, hist b);
    friend std::ostream &    operator<<(std::ostream & a, hist &b);
protected:

private:
    double p;
    double q;
};

