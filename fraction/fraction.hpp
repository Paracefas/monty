#pragma once

#include <iostream>
#include <set>

namespace Paracefas 
{
    class Fraction
    {
        int m_numerator, m_denominator = 1;
        std::set<int>&& factorsOf(int);
    public:
        Fraction(int);
        Fraction(int, int, bool=false);
        Fraction& Simplify();
        double toDouble();
        friend std::ostream& operator<<(std::ostream&, Fraction);
    };
}