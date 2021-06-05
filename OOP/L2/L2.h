#ifndef L2_H
#define L2_H

#include <string>

using namespace std;

class Fraction {
    public:
        Fraction();
        Fraction(int num, int den);
        
        Fraction(const Fraction& f);


        int getNumerator();
        int getDenominator();

        void setNumerator(int n);
        void setDenominator(int d);

        string toString();

        void add(const Fraction& f);
        void subtract(const Fraction& f);
        void multiply(const Fraction& f);
        void divide(const Fraction& f);

        static Fraction add(const Fraction& f, const Fraction& g);
        static Fraction subtract(const Fraction& f, const Fraction& g);
        static Fraction multiply(const Fraction& f, const Fraction& g);
        static Fraction divide(const Fraction& f, const Fraction& g);
    private:
        int numerator, denominator;
        static int count;
        static int numOfFractions();
    
};

#endif 
