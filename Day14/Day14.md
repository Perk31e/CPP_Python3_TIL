# 도전할 문제 **백준 17484 - 진우의 달 여행(Small)**

## **백준 17484 - 진우의 달 여행(Small)** (https://www.acmicpc.net/problem/17484)

## 문제

우주비행사 진우는 달 여행을 위한 최적의 경로를 찾으려고 합니다. N x M 행렬의 각 칸은 비용을 나타내며, 다음과 같은 조건에서 최소 비용의 경로를 찾아야 합니다:

- 위에서 아래로 내려가야 함
- 방향은 왼쪽 아래, 아래, 오른쪽 아래 중 하나
- 같은 방향으로 두 번 연속 이동할 수 없음

## 접근 방식

### 첫 번째 도전 (baekjoon-17484.cpp)

풀이 방식: 깊이 우선 탐색(DFS)을 사용하여 모든 가능한 경로 탐색

```cpp
// 핵심 로직: DFS로 모든 경로 탐색
int space_move(int y, int x, int prev_dir)
{
    // 기저 조건: 달(맨 아래 행)에 도착한 경우
    if (y == n - 1)
    {
        return mp[y][x];
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

        if (ny >= 0 && ny < n && nx >= 0 && nx < m)
        {
            // 현재 위치 비용 + 다음 이동의 최소 비용
            int next_cost = mp[y][x] + space_move(ny, nx, i);
            min_cost = min(min_cost, next_cost);
        }
    }

    return min_cost;
}

// 메인 함수에서는 모든 열에서 출발해보기
for (int i = 0; i < m; i++)
{
    int tmp_cost = space_move(0, i, -1);
    min_cost = min(min_cost, tmp_cost);
}
```

### 두 번째 도전 (baekjoon-17484-dp.cpp)

풀이 방식: 동적 계획법(DP)을 적용하여 중복 계산 제거

```cpp
// DP 상태 정의: dp[y][x][dir] = y,x 위치에 dir 방향에서 왔을 때의 최소 비용
int dp[6][6][3];

// 핵심 로직: 메모이제이션을 적용한 DFS
int space_move(int y, int x, int prev_dir)
{
    // 기저 조건: 달(맨 아래 행)에 도착한 경우
    if (y == n - 1)
    {
        return mp[y][x];
    }

    // 이미 계산된 상태라면 저장된 값 반환 (메모이제이션)
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

        if (ny >= 0 && ny < n && nx >= 0 && nx < m)
        {
            int next_cost = mp[y][x] + space_move(ny, nx, i);
            min_cost = min(min_cost, next_cost);
        }
    }

    // 계산된 최소 비용을 DP 테이블에 저장
    return dp[y][x][prev_dir] = min_cost;
}

// 메인 함수의 핵심 부분
// DP 테이블 초기화
fill(&dp[0][0][0], &dp[0][0][0] + 6 * 6 * 3, -1);

// 모든 열에서 출발해보기
for (int i = 0; i < m; i++)
{
    for (int dir = 0; dir < 3; dir++)
    {
        int cost = space_move(0, i, dir);
        min_cost = min(min_cost, cost);
    }
}
```

## 깨달은 점

**재귀와 DP의 효과적인 활용**

1. **기저 조건(Base Case)의 중요성**

   - 재귀 함수에서 `if (y == n - 1)` 조건은 종료 시점을 정의함
   - 이것이 없으면 무한 재귀로 스택 오버플로우 발생 가능

2. **중복 계산 제거를 통한 효율성 향상**

   - 순수 재귀만 사용하면 많은 상태가 중복 계산되어 메모리 초과 발생
   - DP 배열(dp[y][x][prev_dir])을 통해 이미 계산한 상태 재활용

3. **상태 설계의 중요성**

   - 이전 방향을 상태에 포함시켜 "같은 방향으로 두 번 연속 이동할 수 없음" 조건 처리
   - 3차원 배열(dp[y][x][prev_dir])을 통해 필요한 모든 정보 저장

4. **최적 부분 구조(Optimal Substructure) 활용**

   - 각 위치에서의 최소 비용은 다음 위치들의 최소 비용으로부터 결정됨
   - 이는 DP 적용의 핵심 조건

5. **배열 초기화 방법**
   - `memset(dp, -1, sizeof(dp))` 또는 `fill(&dp[0][0][0], &dp[0][0][0] + 6 * 6 * 3, -1)` 모두 가능
   - DP 상태 초기화는 아직 계산하지 않은 상태(-1)로 설정하는 것이 중요
