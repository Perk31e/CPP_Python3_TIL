#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

int w, h;
int current_map[50][50];
bool visited[50][50];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int start_x, int start_y)
{
    stack<pair<int, int>> stack;
    stack.push({start_x, start_y});
    visited[start_x][start_y] = true;

    while (!stack.empty())
    {
        int x = stack.top().first;
        int y = stack.top().second;
        stack.pop();

        for (int i = 0; i < 8; i++) // 8방향으로 변경
        {
            int nx = x + dx[i];
            int ny = y + dy[i]; // y로 수정

            if (nx >= 0 && nx < h && ny >= 0 && ny < w &&
                !visited[nx][ny] && current_map[nx][ny] == 1)
            {
                visited[nx][ny] = true; // == 대신 = 사용
                stack.push({nx, ny});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;

        // 맵 입력
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> current_map[i][j];
            }
        }

        // 방문 여부 초기화
        fill(&visited[0][0], &visited[0][0] + 50 * 50, false);

        int island_count = 0;

        // 섬 탐색
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (!visited[i][j] && current_map[i][j] == 1)
                {
                    dfs(i, j);
                    island_count++;
                }
            }
        }

        cout << island_count << '\n';
    }

    return 0;
}