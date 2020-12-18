#ifndef CPLIB_IO_HPP
#define CPLIB_IO_HPP

#include <iostream>
#include <iterator>

template <typename InputIt,
          typename T = typename std::iterator_traits<InputIt>::value_type>
void read_n(InputIt it, int n)
{
    copy_n(std::istream_iterator<T>(std::cin), n, it);
}

template <typename InputIt,
          typename T = typename std::iterator_traits<InputIt>::value_type>
void write(InputIt first, InputIt last, const char *delim = "\n")
{
    copy(first, last, std::ostream_iterator<T>(std::cout, delim));
}

#endif // CPLIB_IO_HPP
