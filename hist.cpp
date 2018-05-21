#include "hist.h"
#include <iostream>
#include <ostream>
#include <string>
#include <cstdio>

hist::hist(double a, double b)
{
    p=a;
    q=b;
}
hist::hist() {}
bool operator==(hist a, hist b)
{
    if((a.p/a.q)==(b.p/b.q))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator<(hist a, hist b)
{
    if(((a.p)/(a.q))<((b.p)/(b.q)))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator>(hist a, hist b)
{
    if(((a.p)/(a.q))>((b.p)/(b.q)))
    {
        return true;
    }
    else
    {
        return false;
    }
}
std::ostream &    operator<<(std::ostream & a, hist &b)
{
    a<<b.p<<"/"<<b.q<<std::endl;
    return a;

}

