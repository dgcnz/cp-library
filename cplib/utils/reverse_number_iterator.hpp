#ifndef CPLIB_REVERSE_NUMBER_ITERATOR_HPP
#define CPLIB_REVERSE_NUMBER_ITERATOR_HPP

#include <cplib/utils/number_iterator.hpp>

template <typename T>
class ReverseNumberIterator : public NumberIterator<T>
{
    T n;

  public:
    using self = NumberIterator<T>;
    ReverseNumberIterator(T n) : NumberIterator<T>(n) {}

    self &operator++(int) { return this->operator--(0); }
    self &operator++() { return this->operator--(); }
    self &operator--(int) { return this->operator++(0); }
    self &operator--() { return this->operator++(); }
};

#endif // CPLIB_REVERSE_NUMBER_ITERATOR_HPP
