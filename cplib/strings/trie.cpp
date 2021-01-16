template <typename T>
struct Trie
{
    int               n, nmax;
    vector<vector<T>> t;

    Trie(int maxlen, int alphasz) : n(0), nmax(nmax)
    {
        t.assign(nmax, vector<T>(alphasz, 0));
    }
    void add(const string &s)
    {
        int cur = 0;
        for (int i = isz(s) - 1; i >= 0; --i)
        {
            int j = s[i] - 'a';
            if (!t[cur][j])
                t[cur][j] = ++n;
            cur = t[cur][j];
        }
    }

    int accumulate(const string &s, int pos, vi &dp) const
    {
        int cur = 0, ans = 0;
        for (int i = pos; i >= 0; --i)
        {
            int j   = s[i] - 'a';
            int nxt = t[cur][j];
            if (!nxt)
                break;
            if (cnt[nxt] and (pos - i + 1) % 2 == i % 2)
            {
                ans += (ll(cnt[nxt]) * ll(dp[i])) % MOD;
                ans %= MOD;
            }
            cur = nxt;
        }
        return ans % MOD;
    }
};
