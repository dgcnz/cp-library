#ifndef CPLIB_BINARY_SEARCH_HPP
#define CPLIB_BINARY_SEARCH_HPP

#include <algorithm>
#include <cassert>
#include <functional>

template <typename T>
T binary_search(T lo, T hi, std::function<bool(T)> p)
{
    assert(lo <= hi);
    while (lo < hi)
    {
        T mid = lo + (hi - lo) / 2;
        if (p(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    if (p(lo) == false)
        return -1; // p(x) is false for all x
    return lo;
}

#endif // CPLIB_BINARY_SEARCH_HPP
