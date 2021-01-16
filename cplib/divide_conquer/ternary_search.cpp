#include <algorithm>
#include <functional>

using namespace std;
using predicate     = function<bool(int)>;
using cost_function = function<int(int)>;

// last true in [true, true,... true, false, ... false]
int binary_search(int lo, int hi, predicate p)
{
    while (lo < hi)
    {
        int mid = lo + (hi - lo + 1) / 2;
        if (p(mid) == false)
            hi = mid - 1;
        else
            lo = mid;
    }
    if (p(lo) == false)
        return -1; // p(x) is false for all x
    return lo;
}

int ternary_search(int lo, int hi, cost_function f)
{
    while (hi - lo > 1)
    {
        int mid = (hi + lo) >> 1;
        if (f(mid) > f(mid + 1))
            hi = mid;
        else
            lo = mid;
    }
    return lo;
}
