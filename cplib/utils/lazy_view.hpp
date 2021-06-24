#ifndef CPLIB_LAZY_VIEW_HPP
#define CPLIB_LAZY_VIEW_HPP

#include <cplib/utils/lazy_state>
#include <exception>
#include <iterator>
#include <stdexcept>
#include <type_traits>
#include <vector>
namespace cplib
{
using namespace std;
template <class S, typename T>
struct lazy_view
{
    using iterator_category = std::forward_iterator_tag;
    using difference_type   = std::ptrdiff_t;
    using value_type        = T;
    using pointer           = T *;
    using reference         = T &;
    using self              = lazy_view<S, T>;

  private:
    S    state;
    bool terminated;

  public:
    lazy_view(S _state, bool terminated) : state(_state), terminated(terminated)
    {
    }

    lazy_view &operator++()
    {
        if (!state.terminated())
            state.next();
        terminated = state.terminated();
        return *this;
    }
    T operator*() { return state.value(); }

    inline bool operator==(lazy_view<S, T> const &other) const
    {
        if (terminated or other.terminated)
            return terminated == other.terminated;
        return state.value() == other.state.value();
    }
    inline bool operator!=(lazy_view const &other) const
    {
        return !(operator==(other));
    }

    lazy_view<S, T> begin() { return lazy_view(state, state.terminated()); }
    lazy_view<S, T> end() { return lazy_view(state, true); }
};
} // namespace cplib

#endif // CPLIB_LAZY_VIEW_HPP
