#ifndef CPLIB_LAZY_VECTOR_HPP
#define CPLIB_LAZY_VECTOR_HPP

#include <cplib/utils/lazy_state>
#include <cplib/utils/lazy_vector_iterator>
#include <exception>
#include <iterator>
#include <stdexcept>
#include <type_traits>
#include <vector>

namespace cplib
{
using namespace std;

template <class S, typename T>
struct lazy_vector_iterator;

using namespace std;

template <class S, typename T>
struct lazy_vector
{
    using self     = lazy_vector<S, T>;
    using iterator = lazy_vector_iterator<S, T>;
    vector<T> v;

  private:
    S state;

  public:
    lazy_vector(S _state, int len = 0) : state(_state)
    {
        if (len)
            v.reserve(len);
        state.init();
        if (!state.terminated())
            v.push_back(state.value());
    }
    T operator[](int i)
    {
        cache(i);
        if (i >= (int)v.size())
            throw std::out_of_range("Out of bounds in lazy_vector");
        return v[i];
    }
    void cache(int i)
    {
        if (i >= (int)v.size())
        {
            if (state.terminated())
                return;
            while (i >= (int)v.size())
            {
                state.next();
                if (state.terminated())
                    return;
                v.push_back(state.value());
            }
        }
    }
    bool cached() const { return state.terminated(); }
    void cache_next() { cache(v.size()); }
    void cache_all()
    {
        while (!state.terminated())
            cache_next();
    }

    size_t size()
    {
        if (not cached())
            cache_all();
        return v.size();
    }

    size_t   cached_size() { return v.size(); }
    iterator begin() { return iterator(*this, 0, state.terminated()); }
    iterator end() { return iterator(*this, -1, true); }
};
} // namespace cplib

#endif // CPLIB_LAZY_VECTOR_HPP
