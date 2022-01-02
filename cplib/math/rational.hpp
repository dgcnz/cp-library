#ifndef CPLIB_RATIONAL_HPP
#define CPLIB_RATIONAL_HPP
#include <iostream>
#include <numeric>

// source: https://hitonanode.github.io/cplib-cpp/rational/rational_number.hpp

// rational number + {infinity(1 / 0), -infinity(-1 / 0)}
//
namespace cplib
{
using namespace std;
template <typename T = long long int>
struct rational
{
    T num, den;
    rational(T num = 0, T den = 1) : num(num), den(den) { normalize(); }
    void normalize()
    {
        auto g = gcd(num, den);
        num /= g, den /= g;
        if (den < 0)
            num = -num, den = -den;
    }
    rational operator+(const rational &r) const
    {
        return rational(num * r.den + den * r.num, den * r.den);
    }
    rational operator-(const rational &r) const
    {
        return rational(num * r.den - den * r.num, den * r.den);
    }
    rational operator*(const rational &r) const
    {
        return rational(num * r.num, den * r.den);
    }
    rational operator/(const rational &r) const
    {
        return rational(num * r.den, den * r.num);
    }
    rational &operator+=(const rational &r) { return *this = *this + r; }
    rational &operator-=(const rational &r) { return *this = *this - r; }
    rational &operator*=(const rational &r) { return *this = *this * r; }
    rational &operator/=(const rational &r) { return *this = *this / r; }
    rational  operator-() const { return rational(-num, den); }
    rational  abs() const { return rational(num > 0 ? num : -num, den); }
    bool      operator==(const rational &r) const
    {
        return num == r.num and den == r.den;
    }
    bool operator!=(const rational &r) const
    {
        return num != r.num or den != r.den;
    }
    bool operator<(const rational &r) const
    {
        if (den == 0 and r.den == 0)
            return num < r.num;
        else if (den == 0)
            return num < 0;
        else if (r.den == 0)
            return r.num > 0;
        else
            return num * r.den < den * r.num;
    }
    bool operator<=(const rational &r) const
    {
        return (*this == r) or (*this < r);
    }
    bool operator>(const rational &r) const { return r < *this; }
    bool operator>=(const rational &r) const
    {
        return (r == *this) or (r < *this);
    }
    explicit operator double() const { return (double)num / (double)den; }
    explicit operator long double() const
    {
        return (long double)num / (long double)den;
    }
    friend std::ostream &operator<<(std::ostream &os, const rational &x)
    {
        return os << x.num << '/' << x.den;
    }
};
} // namespace cplib

#endif // CPLIB_RATIONAL_HPP
