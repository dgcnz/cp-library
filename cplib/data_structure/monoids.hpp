
namespace cplib
{

namespace RangeUpdate
{
namespace Sum
{
struct S
{
    int       n;
    long long sum;
};
S op(S a, S b) { return {a.n + b.n, a.sum + b.sum}; }
S e() { return {0, 0}; }
using F = long long;
S mapping(F f, S x) { return {x.n, x.sum + x.n * f}; }
F composition(F f, F g) { return f + g; }
F id() { return 0LL; }
} // namespace Sum
} // namespace RangeUpdate

namespace PointUpdate
{
namespace Sum
{
using S = long long;
S op(S a, S b) { return a + b; }
S e() { return 0; }
} // namespace Sum

namespace Min
{
using S = long long;
S op(S a, S b) { return (a < b ? a : b); }
S e() { return 1e18; }

} // namespace Min
} // namespace PointUpdate

}; // namespace cplib
