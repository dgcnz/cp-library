#include <algorithm>
#include <functional>
#include <vector>

template <typename T>
struct LazySegmentTree
{
    using BinaryOperator = std::function<T(T, T)>;

    T              id;
    BinaryOperator op;

    int            n;
    std::vector<T> seg, lazy;

    template <class InputIterator>
    explicit LazySegmentTree(InputIterator  first,
                             InputIterator  last,
                             T              id,
                             BinaryOperator op)
        : id(id), op(op), n(distance(first, last))
    {
        seg.resize(4 * n), lazy.resize(4 * n);
        build(first, last, 1, 0, n - 1);
    }

    template <class InputIterator>
    void build(InputIterator first, InputIterator last, int v, int tl, int tr)
    {
        if (tl == tr)
            seg[v] = T(*(first + tl));
        else
        {
            int tm = (tl + tr) / 2;
            build(first, last, v << 1, tl, tm);
            build(first, last, (v << 1) + 1, tm + 1, tr);
            seg[v] = op(seg[v << 1], seg[(v << 1) + 1]);
        }
    }

    // Computes current node and propagates change to lazy subtrees
    void lazy_propagate(int v, int tl, int tr, T val)
    {
        // TODO: How do we lazy propagate
        seg[v] += (tr - tl + 1) * val; // Apply changes
        if (tl != tr) // If non-leaf, propagate lazily to children
        {
            lazy[(v << 1)] += val;
            lazy[(v << 1) + 1] += val;
        }
        lazy[v] = 0; // Clear node
    }

    // [tl, tr] : tree's range
    // [ql, qr] : query's range

    void update(int v, int tl, int tr, int ql, int qr, T x)
    {

        if (lazy[v] != 0) // Pending update. Propagate lazily on children.
            lazy_propagate(v, tl, tr, lazy[v]);

        if (ql > qr) // no overlap
            return;

        if (tl == ql and tr == qr) // complete overlap
            lazy_propagate(
                v, tl, tr, x); // Apply x to node, lazily propagate to children
        else                   // partial overlap
        {
            int tm = (tl + tr) / 2;
            update(v * 2, tl, tm, ql, std::min(qr, tm), x);
            update(v * 2 + 1, tm + 1, tr, std::max(ql, tm + 1), qr, x);

            seg[v] = op(seg[v << 1], seg[(v << 1) + 1]);
        }
    }

    T query(int v, int tl, int tr, int ql, int qr)
    {
        if (lazy[v] != 0) // Pending update. Propagate on children.
            lazy_propagate(v, tl, tr, lazy[v]);

        if (ql > qr) // no overlap
            return 0;
        if (tl == ql and tr == qr) // complete overlap
            return seg[v];
        else // partial overlap
        {
            int tm = (tl + tr) / 2;
            return op(query(v * 2, tl, tm, ql, std::min(qr, tm)),
                      query(v * 2 + 1, tm + 1, tr, std::max(ql, tm + 1), qr));
        }
    }
};
