#include <vector>

// source: https://ei1333.github.io/library/structure/segment-tree/persistent-segment-tree.cpp

namespace cplib
{
using namespace std;

template <typename S, S (*op)(S, S), S (*e)()>
struct PersistentSegmentTree
{
    struct Node
    {
        S     data;
        Node *l, *r;

        Node(const S &data) : data(data), l(nullptr), r(nullptr) {}
    };

    int n;

    PersistentSegmentTree() {}

    Node *build(vector<S> &v)
    {
        n = (int)v.size();
        return build(0, (int)v.size(), v);
    }

    Node *merge(Node *l, Node *r)
    {
        auto t = new Node(op(l->data, r->data));
        t->l   = l;
        t->r   = r;
        return t;
    }

    Node *build(int l, int r, vector<S> &v)
    {
        if (l + 1 >= r)
            return new Node(v[l]);
        return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));
    }

    Node *update(int a, const S &x, Node *k, int l, int r)
    {
        if (r <= a || a + 1 <= l)
            return k;
        else if (a <= l && r <= a + 1)
            return new Node(x);
        else
            return merge(update(a, x, k->l, l, (l + r) >> 1),
                         update(a, x, k->r, (l + r) >> 1, r));
    }

    Node *update(Node *t, int k, const S &x) { return update(k, x, t, 0, n); }

    S query(int a, int b, Node *k, int l, int r)
    {
        if (r <= a || b <= l)
            return e();
        else if (a <= l && r <= b)
            return k->data;
        else
            return op(query(a, b, k->l, l, (l + r) >> 1),
                      query(a, b, k->r, (l + r) >> 1, r));
    }

    S query(Node *t, int a, int b) { return query(a, b, t, 0, n); }
};
} // namespace cplib
