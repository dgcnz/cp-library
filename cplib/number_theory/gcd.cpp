
// Euclides' algorithm
//
// Key insight to remember:
//
// Euclides' algorithm is based on two observations:
//
// 1. if b divides a, then gcd(a, b) = b
// 2. a = bd + r, gcd(a, b) = gcd(b, r)

template <typename T>
T gcd(T a, T b)
{
    return (b == 0 ? a : gcd(b, a % b));
}

// Observations
// 1. lcm(a, b) >= max(a, b);
// 2. lcm(a, b) <= a * b

template <typename T>
T lcm(T a, T b)
{
    return ((a * b) / gcd(a, b));
}
