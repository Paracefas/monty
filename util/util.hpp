#pragma once

#include <algorithm>
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
