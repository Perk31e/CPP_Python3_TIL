#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int map[100][100];
bool visited[100][100];

// 4방향 이동을 위한 배열  (상, 우, 하, 좌)
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// DFS 함수
void dfs(int x, int y, int height)
{
    visited[x][y] = true;

    // 4방향 탐색
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 맵 범위 내에 있고, 방문하지 않았으며, 높이가 기준 이상인 경우
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && map[nx][ny] > height)
        {
            dfs(nx, ny, height);
        }
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int maxheight = 0;

    // 지역의 높이 정보 입력 받기
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            maxheight = max(maxheight, map[i][j]);
        }
    }

    // 아무 지역도 잠기지 않을 경우 안전 영역은 1개
    int maxSafeArea = 1;

    // 모든 가능한 높이에 대해 안전 영역 개수 계산
    // 높이가 0부터 시작하는 이유는 비가 전혀 오지 않는 경우도 고려
    for (int height = 0; height < maxheight; height++)
    {
        // 방문 배열 초기화
        fill(&visited[0][0], &visited[0][0] + 100 * 100, false);
        int safeArea = 0;

        // 모든 지역에 대해 DFS 수행
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!visited[i][j] && map[i][j] > height)
                {
                    dfs(i, j, height);
                    safeArea++; // 연결된 안전 영역 하나 발견
                }
            }
        }
        // 최대 한전 영역 개수 갱신
        maxSafeArea = max(maxSafeArea, safeArea);
    }
    cout << maxSafeArea << '\n';
    return 0;
}