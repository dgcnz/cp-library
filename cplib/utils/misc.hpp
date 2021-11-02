#ifndef CPLIB_UTILS_MISC_HPP
#define CPLIB_UTILS_MISC_HPP

#include <algorithm>
#include <cassert>
#include <functional>
#include <map>
#include <numeric>
#include <vector>

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

template <typename T>
long long count_inversions(vector<T> const &a)
{
    int       n   = a.size();
    long long ans = 0;
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < i; ++j)
            ans += a[i] < a[j];
    return ans;
}

long long permutation_sign(vector<int> const &sigma)
{
    return count_inversions(sigma) & 1LL ? -1 : +1;
}

template <typename InputIt,
          typename T    = typename iterator_traits<InputIt>::value_type,
          class Compare = std::less<T>>
vector<int> argsort(InputIt first, InputIt last, Compare cmp = std::less<T>())
{
    vector<int> indices(distance(first, last));
    std::iota(indices.begin(), indices.end(), 0);
    std::sort(indices.begin(),
              indices.end(),
              [&](int i, int j) { return cmp(*(first + i), *(first + j)); });
    return indices;
}

template <typename InputIt,
          typename T    = typename iterator_traits<InputIt>::value_type,
          class Compare = std::less<T>>
vector<int>
stable_argsort(InputIt first, InputIt last, Compare cmp = std::less<T>())
{
    vector<int> indices(distance(first, last));
    std::iota(indices.begin(), indices.end(), 0);
    std::sort(indices.begin(),
              indices.end(),
              [&](int i, int j)
              {
                  T a = *(first + i), b = *(first + j);
                  if (!cmp(a, b) and !cmp(b, a)) // equal
                      return i < j;
                  return cmp(a, b);
              });
    return indices;
}

template <typename InputIt,
          typename T = typename iterator_traits<InputIt>::value_type>
vector<T>
apply_permutation(InputIt first, InputIt last, vector<int> const &sigma)
{
    int n = distance(first, last);
    assert(n == (int)sigma.size());
    vector<T> a_sigma(n);
    for (int i = 0; i < n; ++i)
        a_sigma[i] = *(first + sigma[i]);
    return a_sigma;
}

vector<int> inverse_permutation(vector<int> const &sigma)
{
    int         n = sigma.size();
    vector<int> inv(n);
    for (int i = 0; i < n; ++i)
        inv[sigma[i]] = i;
    return inv;
}

template <typename T>
map<T, int> compress(vector<T> values)
{
    map<T, int> mp;
    int         cnt = 0;
    for (auto v : values)
        mp[v];
    for (auto &[k, v] : mp)
        v = cnt++;
    return mp;
}

} // namespace cplib

#endif // CPLIB_UTILS_MISC_HPP
