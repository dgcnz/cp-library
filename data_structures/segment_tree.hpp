#ifndef SEGMENT_TREE_HPP
#define SEGMENT_TREE_HPP

#include <functional>
#include <vector>

template <class T>
struct SegmentTree
{
    using BinaryOperator = std::function<T(T, T)>;

    T              id;
    BinaryOperator op;

    int            n;
    std::vector<T> t;

    template <class InputIterator>
    explicit SegmentTree(InputIterator  first,
                         InputIterator  last,
                         T              id,
                         BinaryOperator op)
        : id(id), op(op), n(distance(first, last))
    {
        t.resize(4 * n);
        build(first, last, 1, 0, n - 1);
    }

    template <class InputIterator>
    void build(InputIterator first, InputIterator last, int v, int tl, int tr)
    {
        if (tl == tr)
            t[v] = T(*(first + tl));
        else
        {
            int tm = (tl + tr) / 2;
            build(first, last, v << 1, tl, tm);
            build(first, last, (v << 1) + 1, tm + 1, tr);
            t[v] = op(t[v << 1], t[(v << 1) + 1]);
        }
    }

    T query(int l, int r) const { return query(1, 0, n - 1, l, r); }
    T query(int v, int tl, int tr, int l, int r) const
    {
        if (l > r)
            return id;
        if (l == tl and r == tr)
            return t[v];
        int tm = (tl + tr) >> 1;

        // min(r, tm), when we split we only care about the left part, but if
        // the range exceeds the queried range, then the remaining is
        // unnecessary, so pick r.
        return op(query(v << 1, tl, tm, l, std::min(r, tm)),
                  query((v << 1) + 1, tm + 1, tr, std::max(l, tm + 1), r));
    }

    void update(int pos, T val) { return update(1, 0, n - 1, pos, val); }
    void update(int v, int tl, int tr, int pos, T val)
    {
        if (tl == tr)
            t[v] = val;
        else
        {
            int tm = (tl + tr) >> 1;

            if (pos <= tm)
                update(v << 1, tl, tm, pos, val);
            else
                update((v << 1) + 1, tm + 1, tr, pos, val);
            t[v] = op(t[v << 1], t[(v << 1) + 1]);
        }
    }
};

#endif /* SEGMENT_TREE_HPP */
