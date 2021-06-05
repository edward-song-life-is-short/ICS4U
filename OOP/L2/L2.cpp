#include "L2.h"
#include <iostream>
#include <sstream>

int Fraction::count = 0;

int lcmC(int d1, int d2)
{
    int lcm = 0;
    
    if (d1 > d2)
        lcm = d1;
    else
        lcm = d2;
    while (1)
    {
        if (lcm % d1 == 0 && lcm % d2 == 0)
        {
            break;
        }
        lcm++;
    }
    return lcm;
}




Fraction::Fraction()
{
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(int n, int d)
{
    numerator = n;

    if (d == 0)
    {
        denominator = 1;
    }
    else
    {
        denominator = d;;
    }
}

Fraction::Fraction(const Fraction& f) {
    numerator = f.numerator;
    denominator = f.denominator;
}

void Fraction::add(const Fraction& f) {
    int lcm = lcmC(denominator, f.denominator);

    int factor1 = lcm/denominator;
    int factor2 = lcm/f.denominator;

    numerator*=factor1;
    numerator += f.numerator * factor2;
    denominator = lcm;


}

void Fraction::subtract(const Fraction& f) {
    int lcm = lcmC(denominator, f.denominator);

    int factor1 = lcm/denominator;
    int factor2 = lcm/f.denominator;

    numerator*=factor1;

    numerator-= f.numerator * factor2;
    denominator = lcm;
}

void Fraction::multiply(const Fraction& f) {
    numerator *= f.numerator;
    denominator *= f.denominator;
    
}
void Fraction::divide(const Fraction& f) {
    numerator *= f.denominator;
    denominator *= f.numerator;
}

Fraction Fraction::add(const Fraction& f, const Fraction& g) {
    Fraction sum = f;
    sum.add(g);
    return sum;
}

Fraction Fraction::subtract(const Fraction& f, const Fraction& g) {
    Fraction diff = f;
    diff.subtract(g);
    return diff;
}

Fraction Fraction::multiply(const Fraction& f, const Fraction& g) {
    Fraction prod = f;
    prod.multiply(g);
    return prod;
}

Fraction Fraction::divide(const Fraction& f, const Fraction& g) {
    Fraction div = f;
    div.divide(g);
    return div; 
}

int Fraction::numOfFractions()
{
    return count++;
}

int Fraction::getNumerator()
{
    return numerator;
}

int Fraction::getDenominator()
{
    return denominator;
}

void Fraction::setNumerator(int n)
{
    numerator = n;
}

void Fraction::setDenominator(int d)
{
    denominator = d;
}

string Fraction::toString()
{
    stringstream ss;

    ss << numerator;
    ss << "/";
    ss << denominator;

    return ss.str();
}

int main()
{
    Fraction frac(1,2);
    Fraction frac1(1,2);


    Fraction divide = Fraction::divide(frac, frac1);
    cout << divide.toString();

    
}
