#ifndef CPLIB_LAZY_STATE_HPP
#define CPLIB_LAZY_STATE_HPP

namespace cplib
{
template <typename T>
struct LazyState
{
    virtual T    value() const      = 0;
    virtual void next()             = 0;
    virtual void init()             = 0;
    virtual bool terminated() const = 0;
};
} // namespace cplib

#endif // CPLIB_LAZY_STATE_HPP
