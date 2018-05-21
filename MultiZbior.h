#include <iostream>
#include <ostream>
#include <string>
#include <cstdio>
using namespace std;

template <class T> //szablon multizbioru z dowolna klasa T
class Multizbior
{
    friend class Multizbiortest; // zaprzyjazniam z klasa testowa
private:
    T** tablica; //tworze podwojny wskaznik, ma to na celu stworzenie takiej tablicy, ktora bedzie sie rozszerzala w nieskonczonosc, wraz z dodawanymi elementami
    int rozmiar;
    T zwroc(int i) // niezbyt potrzebna metoda, ale za duzo by bylo pracy z usuwaniem jej
    {
        return *tablica[i];
    }
public:
    Multizbior() :tablica(nullptr), rozmiar(0) {}; //lista inicjalizacyjna
    void DrukujMultizbior() // wyswietlanie zawartosci multizbioru
    {
        for(int i=0; i<rozmiar; i++)
        {
            cout<<*tablica[i];
        }
        cout<<endl;
    }
    void DodajElement(const T nowyElement) //dodawanie nowego elementu poprzez tworzenie nowych tablic o rozmiar wiekszych od poprzednich z pozadanym elementem na ostatnim miejscu
    {
        T** buffor = new T*[rozmiar + 1];
        for (int i = 0; i < rozmiar; i++)
        {
            buffor[i] = tablica[i];
        }
        buffor[rozmiar] = new T(nowyElement);
        delete[] tablica;
        tablica = buffor;
        rozmiar++;
    };
    void UsunElement() // usuwanie elementu
    {
        delete tablica[rozmiar-1];
        rozmiar=rozmiar-1;
    }
    bool SprawdzCzyNalezy(T x) // sprawdzanie czy element z argumentu nalezy do multizbioru
    {
        for(int i=0; i<rozmiar; i++)
        {
            if(x==*tablica[i])
            {
                return true;
            }
        }
        return false;
    }
    int IleDanegoElementu(T x) // liczy ilosc elementu z argumentu w calym multizbiorze
    {
        int ile=0;
        for(int i=0; i<rozmiar; i++)
        {
            if(x==*tablica[i])
            {
                ile++;
            }
        }
        return ile;
    }
    int IleWszystkich() // zwraca rozmiar multizbioru (ilosc wszystkich elementow)
    {
        return rozmiar;
    }
    friend bool operator==(Multizbior a, Multizbior b) // przeciazony operator ==
    {
        if(a.rozmiar!=b.rozmiar) // jesli inne rozmiary multizbiorow od razu koncze funkcje
        {
            return false;
        }
        T atablicapomocnicza[a.rozmiar];
        T btablicapomocnicza[b.rozmiar];
        T schowek;
        for(int i=0; i<a.rozmiar; i++) // przypisuje wartosci z pola do tablic pomocniczych statycznych dla ulatwienia i zeby nie zmieniac oryginalnych tablic
        {
            atablicapomocnicza[i]=a.zwroc(i);
        }
        for(int i=0; i<b.rozmiar; i++)
        {
            btablicapomocnicza[i]=b.zwroc(i);
        }
        for( int i = 0; i <a.rozmiar; i++ ) // sortowanie babelkowe
        {
            for( int j = 0; j <a.rozmiar - 1; j++)
            {
                if( atablicapomocnicza[ j ] > atablicapomocnicza[ j + 1 ] )
                {
                    schowek=atablicapomocnicza[j];
                    atablicapomocnicza[j]=atablicapomocnicza[j+1];
                    atablicapomocnicza[j+1]=schowek;
                }

            }
        }
        for( int i = 0; i <b.rozmiar; i++)
        {
            for( int j = 0; j <b.rozmiar - 1; j++ )
            {
                if( btablicapomocnicza[ j ] > btablicapomocnicza[ j + 1 ] )
                {
                    schowek=btablicapomocnicza[j];
                    btablicapomocnicza[j]=btablicapomocnicza[j+1];
                    btablicapomocnicza[j+1]=schowek;
                }

            }
        }
        for(int i=0; i<a.rozmiar; i++) // prosty warunek rownosci na posortowanych tablicach
        {
            if(atablicapomocnicza[i]==btablicapomocnicza[i])
            {
                return true;
            }
        }
        return false;
    }
    friend Multizbior operator+(Multizbior a, Multizbior b) // przeciazony operator dodawania, przepisuje elementy z b.tablicy na koniec a.tablicy
    {
        for(int i=0; i<b.rozmiar; i++)
        {
            a.DodajElement(*b.tablica[i]);
        }
        return a;
    }
    friend Multizbior operator*(Multizbior a, Multizbior b) // przeciazony operator mnozenia (przeciecia)
    {
        T atablicapomocnicza[a.rozmiar]; // robimy praktycznie to samo co w ==
        T btablicapomocnicza[b.rozmiar];
        T schowek;
        for(int i=0; i<a.rozmiar; i++)
        {
            atablicapomocnicza[i]=a.zwroc(i);
        }
        for(int i=0; i<b.rozmiar; i++)
        {
            btablicapomocnicza[i]=b.zwroc(i);
        }
        for( int i = 0; i <a.rozmiar; i++ )
        {
            for( int j = 0; j <a.rozmiar - 1; j++)
            {
                if( atablicapomocnicza[ j ] > atablicapomocnicza[ j + 1 ] )
                {
                    schowek=atablicapomocnicza[j];
                    atablicapomocnicza[j]=atablicapomocnicza[j+1];
                    atablicapomocnicza[j+1]=schowek;
                }

            }
        }
        for( int i = 0; i <b.rozmiar; i++)
        {
            for( int j = 0; j <b.rozmiar - 1; j++ )
            {
                if( btablicapomocnicza[ j ] > btablicapomocnicza[ j + 1 ] )
                {
                    schowek=btablicapomocnicza[j];
                    btablicapomocnicza[j]=btablicapomocnicza[j+1];
                    btablicapomocnicza[j+1]=schowek;
                }

            }
        }
        T ctablicapomocnicza[a.rozmiar]; // deklarujemy trzecia tablice pomocnicza do przechowywania elementow przeciecia zbiorow
        int m, l, k; // algorytm do wyznaczania przeciecia posortowanych mulizbiorow
        int rozmiarc=0;
        k=l=m=0;
        while(k<a.rozmiar && l<b.rozmiar)
        {
            if(atablicapomocnicza[k]==btablicapomocnicza[l])
            {
                ctablicapomocnicza[m]=atablicapomocnicza[k];
                rozmiarc++;
                k++;
                l++;
                m++;
            }
            else
            {
                if(atablicapomocnicza[k]<btablicapomocnicza[l])
                {
                    k++;
                }
                else
                {
                    l++;
                }
            }
        }
        for(int i=0; i<rozmiarc; i++) //przepisuje przeciecie do a
        {
            *a.tablica[i]=ctablicapomocnicza[i];
        }
        for(int i=rozmiarc; i<a.rozmiar; i++) //usuwam zbedne miejsca (przeciecie moze spokojnie miec mniejszy rozmiar od wyjsciowych zbiorow)
        {
            a.UsunElement();
        }
        return a;
    }
};
