#include "Multizbiortest.h"
#include "MultiZbior.h"
#include "hist.h"
#include <iostream>
#include <ostream>
#include <string>
#include <cstdio>
using namespace std;

    void Multizbiortest::testdodawanieusuwanie() // wszystkie testy opieraja sie na tym samym - bierzemy proste multizbiory, ktore moglyby sprawiac problemy dla kiepsko napisanego szablonu, uzywamy metod i porownujemy wyniki z tymi uzyskanymi z glowy. Testuje dla int i hist.
    {
        Multizbior <int> x;
        x.DodajElement(1);
        x.DodajElement(2);
        x.DodajElement(3);
        x.DodajElement(2);
        x.DodajElement(1);
        if(*x.tablica[0]==1 && *x.tablica[1]==2 && *x.tablica[2]==3 && *x.tablica[3]==2 && *x.tablica[4]==1 && x.rozmiar==5)
        {
            cout<<"Dodawanie elementu dziala poprawnie."<<endl;
        }
        else
        {
            cout<<"Dodawanie elementu nie dziala."<<endl;
        }
        x.UsunElement();
        if(*x.tablica[0]==1 && *x.tablica[1]==2 && *x.tablica[2]==3 && *x.tablica[3]==2 && x.rozmiar==4)
        {
            cout<<"Usuwanie elementu dziala poprawnie."<<endl;
        }
        else
        {
            cout<<"Usuwanie elementu nie dziala."<<endl;
        }
    }
    void Multizbiortest::testlicznosci()
    {
        bool t1, t2, t3;
        int it1, it2, it3;
        int wt;
        Multizbior <int> x;
        x.DodajElement(1);
        x.DodajElement(2);
        x.DodajElement(3);
        x.DodajElement(2);
        x.DodajElement(1);
        t1=x.SprawdzCzyNalezy(1);
        t2=x.SprawdzCzyNalezy(2);
        t3=x.SprawdzCzyNalezy(3);
        if(t1==true && t2== true && t3==true)
        {
            cout<<"Sprawdzenie, czy dany element nalezy do multizbioru dziala poprawnie."<<endl;
        }
        else
        {
            cout<<"Sprawdzenie, czy dany element nalezy do multizbioru nie dziala."<<endl;
        }
        it1=x.IleDanegoElementu(1);
        it2=x.IleDanegoElementu(2);
        it3=x.IleDanegoElementu(3);
        if(it1==2 && it2==2 && it3==1)
        {
           cout<<"Sprawdzenie, ile razy dany element wystapi w multizbiorze dziala poprawnie."<<endl;
        }
        else
        {
            cout<<"Sprawdzenie, ile razy dany element wystapi w multizbiorze nie dziala."<<endl;
        }
        wt=x.IleWszystkich();
        if(wt==x.rozmiar && wt==5)
        {
            cout<<"Podanie licznosci multizbioru dziala poprawnie."<<endl;
        }
        else
        {
            cout<<"Podanie licznosci multizbioru nie dziala."<<endl;
        }

    }
    void Multizbiortest::testplus()
    {
      Multizbior <int> x;
      Multizbior <int> y;
      x.DodajElement(1);
      x.DodajElement(2);
      y.DodajElement(3);
      y.DodajElement(4);
      x=x+y;
      if(*x.tablica[0]==1 && *x.tablica[1]==2 && *x.tablica[2]==3 && *x.tablica[3]==4 && x.rozmiar==4)
      {
          cout<<"Dodawanie multizbiorow dziala poprawnie."<<endl;
      }
      else
      {
        cout<<"Dodawanie multizbiorow nie dziala."<<endl;
      }
    }
    void Multizbiortest::testprzeciecia()
    {
      Multizbior <int> x;
      Multizbior <int> y;
      x.DodajElement(1);
      x.DodajElement(2);
      x.DodajElement(1);
      x.DodajElement(3);
      y.DodajElement(1);
      y.DodajElement(1);
      y.DodajElement(1);
      y.DodajElement(3);
      y.DodajElement(3);
      y.DodajElement(5);
      y.DodajElement(8);
      x=x*y;
      if(*x.tablica[0]==1 && *x.tablica[1]==1 && *x.tablica[2]==3 && x.rozmiar==3)
      {
          cout<<"Przeciecie multizbiorow dziala poprawnie."<<endl;
      }
      else
      {
          cout<<"Przeciecie multizbiorow nie dziala."<<endl;
      }
    }
    void Multizbiortest::testrownosci()
    {
      Multizbior <int> x;
      Multizbior <int> y;
      x.DodajElement(1);
      x.DodajElement(2);
      x.DodajElement(1);
      x.DodajElement(3);
      y.DodajElement(1);
      y.DodajElement(1);
      y.DodajElement(3);
      y.DodajElement(2);
      if(x==y)
      {
          cout<<"Porownanie multizbiorow dziala poprawnie."<<endl;
      }
      else
      {
          cout<<"Porownanie multizbiorow nie dziala."<<endl;
      }
    }
    void Multizbiortest::testdodawanieusuwanie2()
    {
        Multizbior < hist > x;
        hist a(1.0, 2.0);
        hist b(1.0, 3.0);
        hist c(1.0, 4.0);
        hist d(1.0, 5.0);
        x.DodajElement(a);
        x.DodajElement(b);
        x.DodajElement(c);
        x.DodajElement(d);
        if(*x.tablica[0]==a && *x.tablica[1]==b && *x.tablica[2]==c && *x.tablica[3]==d && x.rozmiar==4)
        {
            cout<<"Dodawanie elementu klasy uzytkownika dziala poprawnie."<<endl;
        }
        else
        {
            cout<<"Dodawanie elementu klasy uzytkownika nie dziala."<<endl;
        }
        x.UsunElement();
        if(*x.tablica[0]==a && *x.tablica[1]==b && *x.tablica[2]==c && x.rozmiar==3)
        {
            cout<<"Usuwanie elementu klasy uzytkownika dziala poprawnie."<<endl;
        }
        else
        {
            cout<<"Usuwanie elementu klasy uzytkownika nie dziala."<<endl;
        }
    }
    void Multizbiortest::testlicznosci2()
    {
        bool t1, t2, t3;
        int it1, it2, it3;
        int wt;
        Multizbior <hist> x;
        hist a(1.0, 2.0);
        hist b(1.0, 3.0);
        hist c(1.0, 4.0);
        x.DodajElement(a);
        x.DodajElement(b);
        x.DodajElement(c);
        x.DodajElement(c);
        x.DodajElement(a);
        t1=x.SprawdzCzyNalezy(a);
        t2=x.SprawdzCzyNalezy(b);
        t3=x.SprawdzCzyNalezy(c);
        if(t1==true && t2== true && t3==true)
        {
            cout<<"Sprawdzenie, czy dany element klasy uzytkownika nalezy do multizbioru dziala poprawnie."<<endl;
        }
        else
        {
            cout<<"Sprawdzenie, czy dany element klasy uzytkownika nalezy do multizbioru nie dziala."<<endl;
        }
        it1=x.IleDanegoElementu(a);
        it2=x.IleDanegoElementu(b);
        it3=x.IleDanegoElementu(c);
        if(it1==2 && it2==1 && it3==2)
        {
           cout<<"Sprawdzenie, ile razy dany element klasy uzytkownika wystapi w multizbiorze dziala poprawnie."<<endl;
        }
        else
        {
            cout<<"Sprawdzenie, ile razy dany element klasy uzytkownika wystapi w multizbiorze nie dziala."<<endl;
        }
        wt=x.IleWszystkich();
        if(wt==x.rozmiar && wt==5)
        {
            cout<<"Podanie licznosci multizbioru dla klasy uzytkownika dziala poprawnie."<<endl;
        }
        else
        {
            cout<<"Podanie licznosci multizbioru dla klasy uzytkownika nie dziala."<<endl;
        }

    }
    void Multizbiortest::testplus2()
    {
      Multizbior <hist> x;
      Multizbior <hist> y;
      hist a(1.0, 2.0);
      hist b(1.0, 3.0);
      hist c(1.0, 4.0);
      hist d(1.0, 5.0);
      x.DodajElement(a);
      x.DodajElement(b);
      y.DodajElement(c);
      y.DodajElement(d);
      x=x+y;
      if(*x.tablica[0]==a && *x.tablica[1]==b && *x.tablica[2]==c && *x.tablica[3]==d && x.rozmiar==4)
      {
          cout<<"Dodawanie multizbiorow dla klasy uzytkownika dziala poprawnie."<<endl;
      }
      else
      {
        cout<<"Dodawanie multizbiorow dla klasy uzytkownika nie dziala."<<endl;
      }
    }
    void Multizbiortest::testprzeciecia2()
    {
      Multizbior <hist> x;
      Multizbior <hist> y;
      hist a(1.0, 2.0);
      hist b(1.0, 3.0);
      hist c(1.0, 4.0);
      hist d(1.0, 5.0);
      hist e(1.0, 6.0);
      x.DodajElement(a);
      x.DodajElement(b);
      x.DodajElement(a);
      x.DodajElement(c);
      y.DodajElement(a);
      y.DodajElement(a);
      y.DodajElement(a);
      y.DodajElement(c);
      y.DodajElement(c);
      y.DodajElement(d);
      y.DodajElement(e);
      x=x*y;
      if(*x.tablica[0]==c && *x.tablica[1]==a && *x.tablica[2]==a && x.rozmiar==3)
      {
          cout<<"Przeciecie multizbiorow dla klasy uzytkownika dziala poprawnie."<<endl;
      }
      else
      {
          cout<<"Przeciecie multizbiorow dla klasy uzytkownika nie dziala."<<endl;
      }
    }
    void Multizbiortest::testrownosci2()
    {
      Multizbior <hist> x;
      Multizbior <hist> y;
      hist a(1.0, 2.0);
      hist b(1.0, 3.0);
      hist c(1.0, 4.0);
      x.DodajElement(a);
      x.DodajElement(b);
      x.DodajElement(a);
      x.DodajElement(c);
      y.DodajElement(a);
      y.DodajElement(a);
      y.DodajElement(c);
      y.DodajElement(b);
      if(x==y)
      {
          cout<<"Porownanie multizbiorow dla klasy uzytkownika dziala poprawnie."<<endl;
      }
      else
      {
          cout<<"Porownanie multizbiorow dla klasy uzytkownika nie dziala."<<endl;
      }
    }
