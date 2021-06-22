template <typename T>
struct Trie
{
    int                 n, nmax;
    vector<vector<int>> t;
    vector<T>           val;

    Trie(int N, int alphasz) : n(0), t(N, vector<int>(alphasz, 0)), val(N, T())
    {
    }
    void update(const vector<int> &a, function<void(T &)> f)
    {
        int cur = 0;
        for (int i = 0; i < (int)a.size(); ++i)
        {
            if (!t[cur][a[i]])
                t[cur][a[i]] = ++n;
            cur = t[cur][a[i]];
            f(val[cur]);
        }
    }

    void traverse(const vector<int> &a, function<void(T &, int)> f)
    {
        int cur = 0;
        for (int i = 0; i < (int)a.size(); ++i)
        {

            if (!t[cur][a[i]])
                return;

            f(val[t[cur][a[i]]], i);
            cur = t[cur][a[i]];
        }
    }
};
