#include <algorithm>
#include <iterator>
#include <iostream>
#include <ctime>
#include <set>

namespace util
{
    template<typename T>
    std::set<T>&& intersect(std::set<T> const& a, std::set<T> const& b)
    {
        std::set<T> r;
        std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::inserter(r, r.end()));
        return std::move(r);
    }

    template<typename Container>
    auto const max_element(Container const& c)
    {
        return *std::max_element(c.begin(), c.end());
    }
}

class Fraction
{
    int m_numerator, m_denominator = 1;
    std::set<int>&& factorsOf(int x)
    {
        std::set<int> r{1};
        for(int i = 2; i < x; ++i)
            if(!(x % i))
                r.insert(i);
        r.insert(x);
        return std::move(r);
    }
public:
    Fraction(int n) : m_numerator {n} {}
    Fraction(int n, int d, bool simplify = false) : m_numerator {n}, m_denominator {d} 
    {
        if(simplify) Simplify();
    }
    Fraction& Simplify()
    {
        auto F1 = factorsOf(m_numerator);
        auto F2 = factorsOf(m_denominator);
        auto max = util::max_element(util::intersect(F1, F2));
        m_numerator   /= max;
        m_denominator /= max;

        return *this; 
    }

    double toDouble() 
    {
        return m_numerator/m_denominator;
    }
    friend std::ostream& operator<<(std::ostream& os, Fraction f);
};

std::ostream& operator<<(std::ostream& os, Fraction f)
{
    if(f.m_denominator == 1) os << f.m_numerator;
    else os << f.m_numerator << " / " << f.m_denominator;
    return os;
}


int main(int argc, char const** argv)
{
    const int it = argc == 3 ? atoi(argv[1]) : 200;
    const int n  = argc == 3 ? atoi(argv[2]) : 3;

    srand(time(NULL));

    int nochange = 0, change = 0, winpos, chosen;
    
    for(int i = 1; i <= it; ++i)
    {
        winpos = rand() % n;
        chosen = rand() % n;
        winpos==chosen ? nochange++ : change++;
    }

    std::cout << "Change: " << Fraction {change, it} << " - No-change: " << Fraction {nochange, it} << '\n';
}