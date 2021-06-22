#ifndef CPLIB_IO_HPP
#define CPLIB_IO_HPP

#include <iostream>
#include <iterator>

namespace cplib
{
using namespace std;
template <typename InputIt,
          typename T = typename iterator_traits<InputIt>::value_type>
void read_n(InputIt it, int n)
{
    copy_n(istream_iterator<T>(cin), n, it);
}

template <typename InputIt,
          typename T = typename iterator_traits<InputIt>::value_type>
void read(InputIt first, InputIt last)
{
    read_n(first, distance(first, last));
}

template <typename InputIt,
          typename T = typename iterator_traits<InputIt>::value_type>
void write(InputIt first, InputIt last, const char *delim = "\n")
{
    copy(first, last, ostream_iterator<T>(cout, delim));
}

template <typename InputIt,
          typename T = typename iterator_traits<InputIt>::value_type>
void decrement(InputIt first, InputIt last)
{
    transform(first, last, first, [](T x) { return x - 1; });
}

template <typename InputIt,
          typename T = typename iterator_traits<InputIt>::value_type>
void increment(InputIt first, InputIt last)
{
    transform(first, last, first, [](T x) { return x + 1; });
}

} // namespace cplib

#endif // CPLIB_IO_HPP
