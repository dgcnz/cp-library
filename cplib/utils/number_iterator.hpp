#ifndef CPLIB_NUMBER_ITERATOR_HPP
#define CPLIB_NUMBER_ITERATOR_HPP

#include <iterator>

namespace cplib
{

template <typename T = int>
class NumberIterator
{
    T n;

    static_assert(std::is_integral<T>::value, "Integral required.");

  public:
    using self              = NumberIterator<T>;
    using value_type        = T;
    using difference_type   = T;
    using reference         = T &;
    using pointer           = T *;
    using iterator_category = std::random_access_iterator_tag;

    NumberIterator(T n) : n(n) {}
    self &operator=(T n)
    {
        this->n = n;
        return *this;
    }
    T &   operator*() { return n; }
    self  operator+(T delta) const { return self(n + delta); }
    self &operator+=(T delta)
    {
        n += delta;
        return *this;
    }
    self  operator-(T delta) const { return self(n - delta); }
    self &operator++()
    {
        n++;
        return (*this);
    }
    self &operator++(int)
    {
        ++n;
        return *this;
    }
    self &operator--()
    {
        n--;
        return (*this);
    }
    self &operator--(int)
    {
        --n;
        return *this;
    }
    difference_type operator-(const self &rhs) const { return n - rhs.n; }
    bool            operator==(const self &rhs) const { return n == rhs.n; }
    bool     operator!=(const self &rhs) const { return !(*this == rhs.n); }
    explicit operator T() const { return n; }
};

template <typename T>
using nit   = NumberIterator<T>;
using itll  = NumberIterator<long long>;
using itint = NumberIterator<int>;
} // namespace cplib

#endif // CPLIB_NUMBER_ITERATOR_HPP
