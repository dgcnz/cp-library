template <typename T>
map<T, int> compress(vector<T> values)
{
    map<T, int> mp;
    int         cnt = 0;
    for (auto v : values)
        mp[v];
    for (auto &[k, v] : mp)
        v = cnt++;
    return mp;
}
