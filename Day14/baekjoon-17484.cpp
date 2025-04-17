#include <iostream>
#include <vector>
using namespace std;
int mp[6][6];
int n, m;
int dy[] = {1, 1, 1};
int dx[] = {-1, 0, 1};
vector<int> total_cost;
const int INF = 1e9;
int space_move(int y, int x, int prev_dir)
{
    if (y == n - 1)
    {
        return mp[y][x];
    }
    int min_cost = INF;
    for (int i = 0; i < 3; i++)
    {
        if (i == prev_dir)
        {
            continue;
        }
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= 0 && ny < n && nx >= 0 && nx < m)
        {
            int next_cost = mp[y][x] + space_move(ny, nx, i);
            min_cost = min(min_cost, next_cost);
        }
    }
}
int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mp[i][j];
        }
    }
    int min_cost = INF;
    for (int i = 0; i < m; i++)
    {
        // 각 출발점에서 시작했을대 가장 값이 작은걸 찾는다.
        int tmp_cost = space_move(0, i, -1);
        min_cost = min(min_cost, tmp_cost);
    }
    cout << min_cost << '\n';
    return 0;
}