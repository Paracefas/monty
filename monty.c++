#include <iostream>
#include <ctime>

#include "fraction/fraction.hpp"
namespace par = Paracefas;

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

    std::cout << "Change: " << par::Fraction {change, it} << " - No-change: " << par::Fraction {nochange, it} << '\n';
}