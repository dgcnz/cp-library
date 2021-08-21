#ifndef CPLIB_ORDERED_SET_HPP
#define CPLIB_ORDERED_SET_HPP

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iterator>
#include <utility>

namespace cplib
{
using namespace std;
template <typename Key, class Compare = std::less<Key>>
struct ordered_set
{
    using oset =
        __gnu_pbds::tree<Key,
                         __gnu_pbds::null_type,
                         Compare,
                         __gnu_pbds::rb_tree_tag,
                         __gnu_pbds::tree_order_statistics_node_update>;
    using oset_iterator = typename oset::iterator;

    oset ord;
    struct iterator
    {
        using value_type        = Key;
        using difference_type   = std::ptrdiff_t;
        using reference         = Key &;
        using pointer           = Key *;
        using iterator_category = std::random_access_iterator_tag;
        oset_iterator it;
        oset const &  ord;
        iterator(oset_iterator it, oset const &ord) : it(it), ord(ord) {}
        Key       operator*() const { return *it; };
        iterator &operator++()
        {
            it++;
            return *this;
        }
        difference_type operator-(iterator const &other)
        {
            int r = it == ord.end() ? ord.size() : ord.order_of_key(*it);
            int l = other.it == ord.end() ? ord.size()
                                          : ord.order_of_key(*other.it);
            return r - l;
        }
        bool operator==(iterator const &other) const { return it == other.it; }
        bool operator!=(iterator const &other) const { return it != other.it; }
    };

    iterator lower_bound(Key key) const
    {
        return iterator(ord.lower_bound(key), ord);
    }

    iterator upper_bound(Key key) const
    {
        return iterator(ord.upper_bound(key), ord);
    }
    iterator begin() const { return iterator(ord.begin(), ord); }
    iterator end() const { return iterator(ord.end(), ord); }
};

} // namespace cplib

#endif // CPLIB_ORDERED_SET_HPP
