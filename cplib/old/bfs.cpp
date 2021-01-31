
int  n, m, dist[NMAX][NMAX], visited[NMAX][NMAX];
char board[NMAX][NMAX];
int  dr[4] = {1, -1, 0, 0};
int  dc[4] = {0, 0, 1, -1};

inline bool in_bounds(int r, int c)
{
    return 0 <= r and r < n and 0 <= c and c < m;
}

vector<ii> neighbors(int r, int c)
{
    vector<ii> ans;
    for (int i = 0; i < 4; ++i)
    {
        if (in_bounds(r + dr[i], c + dc[i]))
        {
            ans.emplace_back(r + dr[i], c + dc[i]);
        }
    }
    return ans;
}

void bfs(vector<ii> sources)
{
    queue<ii> frontier;
    memset(visited, false, sizeof(visited));
    for (auto x : sources)
        frontier.push(x);

    while (not frontier.empty())
    {
        auto [r, c] = frontier.front();
        frontier.pop();

        for (auto [rr, cc] : neighbors(r, c))
        {
            if (not visited[rr][cc])
            {
                frontier.emplace(rr, cc);
                visited[rr][cc] = true;
                dist[rr][cc]    = dist[r][c] + 1;
            }
        }
    }
}
