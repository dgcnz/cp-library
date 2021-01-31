# Experimental competitive programmming library? WIP

This is some work I've been doing to build my own library and pick/extend other's implementations of common algorithms and data structures in competitive programming. In the spirit of AtCoder's Library, I try to make this implementations as complete and generic as possible to be able to use them as oracles or black boxes.

In some cases (`hld` and `combinatorics`), I use AtCoder's implementations as underlying containers, because they are *fast*.

## Data Structures

- Fenwick Tree (`<atcoder/fenwicktree>`)
- Segment Tree (`<atcoder/segtree>`)
- Lazy Segment Tree (`<atcoder/lazysegtree>`)

## Graphs

- Disjoint Set Union (`<atcoder/dsu>`)
- Dijkstra (`<cplib/graphs/dijkstra>`)
- Topological Sort (`<cplib/graphs/toposort>`)
- LCA w/ binary lifting (`<cplib/graphs/lca>`)
- Heavy-Light Decomposition (`<cplib/graphs/hld>`)
- Strongly Connected Components (`<atcoder/scc>`)

## Math

- Sieve of Eratosthenes (`<cplib/math/sieve>`)
- Binary Exponentiation (`<cplib/math/binary_exponentiation>`)
- Binomial Coefficients (`<cplib/math/combinatorics>`)
- ModInt 1 (`<atcoder/modint>`)
- ModInt 2 (`<cplib/math/modint>`)


There are other algorithms and data structures lying around, that are not included because:
1. I don't know how to package them as an oracle
2. I'm not sure if their use is justified ("too cumbersome" or "experimental").

## Usage

This was my submission to [Path Queries II](https://cses.fi/problemset/task/2134). 

```cpp
// file.cpp
#include <atcoder/segtree>
#include <bits/stdc++.h>
#include <cplib/graphs/hld>

using namespace std;

using S = long long;
S op(S a, S b) { return max(a, b); }
S e() { return 0; }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, q;
    cin >> n >> q;

    vector<int> val(n);
    for (auto &x : val)
        cin >> x;

    HLD<atcoder::segtree, S, op, e> hld(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v, u--, v--;
        hld.add_edge(u, v);
    }

    hld();

    for (int u = 0; u < n; ++u)
        hld.set(u, val[u]);

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int u, x;
            cin >> u >> x, u--;
            hld.set(u, x);
        }
        else
        {
            int u, v;
            cin >> u >> v, u--, v--;
            cout << hld.query(u, v) << " ";
        }
    }
    cout << endl;

    return 0;
}
```

Notes:
1. Make sure you have an environment variable to both libraries (ACL and CPL).
2. `<atcoder/modint>` makes use of 64-bit integers, so beware OJs that don't support it.

```sh
# Will create a file combined.py with everything needed.
python3 $CPLIB/expander.py file.cpp -c --lib $CPLIB | python3 $ACLIB/expander.py /dev/stdin --lib $ACLIB

# Will copy the file file.cpp together with all it needs to your clipboard (xclip needed)
python3 $CPLIB/expander.py file.cpp -c --lib $CPLIB | python3 $ACLIB/expander.py /dev/stdin -c --lib $ACLIB | xclip -selection clipboard
```

I usually pack this in a vim function:

```
function! CPYank ()
    :! python3 $CPLIB/expander.py % -c --lib $CPLIB | python3 $ACLIB/expander.py /dev/stdin -c --lib $ACLIB | xclip -selection clipboard
endfunction

command! CPY call CPYank()
```

And then use `:CPY` in normal mode to copy the contents to my system clipboard.
