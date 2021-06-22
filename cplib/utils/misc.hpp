#ifndef CPLIB_UTILS_MISC_HPP
#define CPLIB_UTILS_MISC_HPP

#include <algorithm>
#include <functional>

namespace cplib
{
using namespace std;

template <class T>
struct minimum : binary_function<T, T, T>
{
    T operator()(const T &x, const T &y) const { return std::min(x, y); }
    template <class Compare>
    T operator()(const T &x, const T &y, Compare comp) const
    {
        return std::min(x, y, comp);
    }
};

template <class T>
struct maximum : binary_function<T, T, T>
{
    T operator()(const T &x, const T &y) const { return std::max(x, y); }
    template <class Compare>
    T operator()(const T &x, const T &y, Compare comp) const
    {
        return std::max(x, y, comp);
    }
};

template <typename T1, typename T2>
vector<pair<T1, T2>> map_union(vector<pair<T1, T2>> const &a,
                               vector<pair<T1, T2>> const &b)
{
    vector<pair<T1, T2>> ans;
    ans.reserve(max(size(a), size(b)));
    int i = 0, j = 0;
    while (i < (int)a.size() and j < (int)b.size())
    {
        if (a[i].first == b[j].first)
        {
            ans.emplace_back(a[i].first, a[i].second + b[j].second);
            i++, j++;
        }
        else if (a[i].first < b[j].first)
            ans.push_back(a[i++]);
        else
            ans.push_back(b[j++]);
    }
    while (i < (int)a.size())
        ans.push_back(a[i++]);

    while (j < (int)b.size())
        ans.push_back(b[j++]);
    return ans;
}

template <typename T1, typename T2>
vector<pair<T1, T2>> map_intersection(vector<pair<T1, T2>> const &a,
                                      vector<pair<T1, T2>> const &b)
{
    vector<pair<T1, T2>> ans;
    int                  i = 0, j = 0;
    while (i < (int)a.size() and j < (int)b.size())
    {
        if (a[i].first == b[j].first)
        {
            ans.emplace_back(a[i].first, min(a[i].second, b[j].second));
            i++, j++;
        }
        else if (a[i].first < b[j].first)
            i++;
        else
            j++;
    }
    return ans;
}
} // namespace cplib

#endif // CPLIB_UTILS_MISC_HPP
