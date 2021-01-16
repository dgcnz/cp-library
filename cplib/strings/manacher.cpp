#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1e5 + 11;
int       n, d1[NMAX], d2[NMAX];

// odd manacher: for each i compute the number of palindromes centered at i
// if i is out of the rightmost palindrome, then do trivial algorithm
// otherwise, let j = l + r - i, the mirror of i on rightmost palindrome
// we have already computed the palindromes of j, d[j]
// however, d[j] borders might exceed the rightmost palindrome with ends [l, r]
// In that, case, just take the minimum of them and extend as much as possible

void manacher(const string &s)
{
    for (int i = 0, l = 0, r = -1; i < n; ++i)
    {
        int j = l + r - i;
        int k = (i > r) ? 1 : min(d1[j], j - l + 1);
        while (0 <= i - k and i + k < n and s[i - k] == s[i + k])
            ++k;
        d1[i] = k--;
        if (i + k > r)
        {
            l = i - k;
            r = i + k;
        }
    }

    for (int i = 0, l = 0, r = -1; i < n; ++i)
    {
        int j = l + r - i;
        int k = (i > r) ? 0 : min(d2[j + 1], j - l + 1);
        while (0 <= i - k - 1 and i + k < n and s[i - k - 1] == s[i + k])
            ++k;
        d2[i] = k--;
        if (i + k > r)
        {
            l = i - k - 1;
            r = i + k;
        }
    }
}
