#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <vector>
using namespace std;

class Fraction
{

public:
    long int numerateur, denominateur;

public:
    Fraction();
    Fraction(const long int & n);
    Fraction(const long int & n, const long int & m);

    friend std::ostream& operator << (std::ostream& flux, Fraction const& fraction);
    Fraction& operator = (const Fraction & f);
    bool estEgal (const Fraction & f) const;
    bool estPlusPetitQue (const Fraction & f) const;
    Fraction& operator += (const Fraction & f);
    Fraction operator + (const long int & f);
    Fraction inverse ();
    long int pgcd (long int a, long int b);
    Fraction simplifie ();
    bool isFraction (const double & d);
    Fraction double2Fraction (const double & f);
    void recursive (std::vector<long int> &tab, const double & rest);
    Fraction hanattal (const double & d);

};



bool operator==(const Fraction & f1, const Fraction & f2);
bool operator<(const Fraction & f1, const Fraction & f2);
Fraction operator+(const Fraction & f1, const Fraction & f2);
Fraction operator* (const Fraction & f1, const Fraction & f2);
Fraction operator+ (const long int & d, const Fraction & f1);
Fraction operator/ (const Fraction & f1, const Fraction & f2);




#endif
