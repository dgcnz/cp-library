#ifndef NUMBER_ITERATOR_HPP
#define NUMBER_ITERATOR_HPP

#include <iterator>

template <typename T = int>
class NumberIterator
{
    T n;

  public:
    using self              = NumberIterator<T>;
    using value_type        = T;
    using difference_type   = T;
    using reference         = T &;
    using pointer           = T *;
    using iterator_category = std::random_access_iterator_tag;

    NumberIterator(T n) : n(n) {}

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
    bool operator!=(const self &rhs) const { return !(*this == rhs.n); }
};

#endif
