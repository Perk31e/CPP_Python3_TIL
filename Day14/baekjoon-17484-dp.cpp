#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int mp[6][6];
int dp[6][6][3]; // dp[y][x][dir] = y,x 위치에 dir 방향에서 왔을 때의 최소 비용
int n, m;
int dy[] = {1, 1, 1};
int dx[] = {-1, 0, 1};
const int INF = 1e9;

// 파라미터: y좌표, x좌표, 이전 이동 방향(0,1,2)
int space_move(int y, int x, int prev_dir)
{
    // 달(맨 아래 행)에 도착한 경우
    if (y == n - 1)
    {
        return mp[y][x];
    }

    // 이미 계산된 상태라면 저장된 값 반환
    if (dp[y][x][prev_dir] != -1)
    {
        return dp[y][x][prev_dir];
    }

    int min_cost = INF;

    // 3가지 방향으로 탐색
    for (int i = 0; i < 3; i++)
    {
        // 같은 방향으로 두 번 연속 이동할 수 없음
        if (i == prev_dir)
        {
            continue;
        }

        int ny = y + dy[i];
        int nx = x + dx[i];

        // 범위 체크
        if (ny >= 0 && ny < n && nx >= 0 && nx < m)
        {
            // 현재 위치 비용 + 다음 이동의 최소 비용
            int next_cost = mp[y][x] + space_move(ny, nx, i);
            min_cost = min(min_cost, next_cost);
        }
    }

    // 계산된 최소 비용을 DP 테이블에 저장
    return dp[y][x][prev_dir] = min_cost;
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

    // DP 테이블 초기화 (-1은 아직 계산하지 않은 상태)
    fill(&dp[0][0][0], &dp[0][0][0] + 6 * 6 * 3, -1);

    int min_cost = INF;

    // 모든 열에서 출발해보기
    for (int i = 0; i < m; i++)
    {
        // 각 방향에서 시작해서 최소값 찾기
        for (int dir = 0; dir < 3; dir++)
        {
            int cost = space_move(0, i, dir);
            min_cost = min(min_cost, cost);
        }
    }

    cout << min_cost << '\n';
    return 0;
}