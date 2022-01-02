#ifndef CPLIB_STRING_UTILS_HPP
#define CPLIB_STRING_UTILS_HPP

#include <string>
#include <vector>

namespace cplib
{
using namespace std;
namespace bounded_lexicographical
{
struct compare
{
    bool operator()(string a, string b) const
    {
        if (a.size() == b.size())
            return a < b;
        return a.size() < b.size();
    }
};
string next(string s)
{
    if (s == "")
        return "a";
    int i = s.size() - 1;
    while (s[i] == 'z' && i >= 0)
        s[i--] = 'a';
    if (i == -1)
        s.push_back('a');
    else
        s[i]++;
    return s;
}
}; // namespace bounded_lexicographical

namespace lexicographical
{
struct compare
{
    bool operator()(string a, string b) const { return a < b; }
};
string next(string s)
{
    if (s == "")
        return "a";
    int i = s.size() - 1;
    while (s[i] == 'z' && i >= 0)
        i--;
    if (i == -1)
        s.push_back('a');
    else
        s[i]++;

    return s;
}
}; // namespace lexicographical

/*
 * @brief Checks if vector is a palindromic sequence
 * @param a vector to be checked for
 */
template <typename T>
bool is_palindrome(vector<T> const &a)
{
    return a == vector<T>(a.rbegin(), a.rend());
}

/*
 * @brief Checks if string is a palindromic sequence
 * @param a string to be checked for
 */
bool is_palindrome(string const &a)
{
    return a == string(a.rbegin(), a.rend());
}

}; // namespace cplib

#endif // CPLIB_STRING_UTILS_HPP
