#include "fraction.hpp"
#include "../util/util.hpp"

namespace Paracefas 
{
    std::set<int>&& Fraction::factorsOf(int x)
    {
        std::set<int> r{1};
        for(int i = 2; i < x; ++i)
            if(!(x % i))
                r.insert(i);
        r.insert(x);
        return std::move(r);
    }

    Fraction::Fraction(int n) : m_numerator {n} {}

    Fraction::Fraction(int n, int d, bool simplify) : m_numerator {n}, m_denominator {d} 
    {
        if(simplify) Simplify();
    }

    Fraction& Fraction::Simplify()
    {
        auto F1 = factorsOf(m_numerator);
        auto F2 = factorsOf(m_denominator);
        auto max = util::max_element(util::intersect(F1, F2));
        m_numerator   /= max;
        m_denominator /= max;

        return *this; 
    }

    double Fraction::toDouble() 
    {
        return m_numerator/m_denominator;
    }

    std::ostream& operator<<(std::ostream& os, Fraction f)
    {
        if(f.m_denominator == 1) os << f.m_numerator;
        else os << f.m_numerator << " / " << f.m_denominator;
        return os;
    }
}