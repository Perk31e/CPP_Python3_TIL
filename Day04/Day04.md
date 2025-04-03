# 도전할 문제 **백준 2468**

## **백준 2468** (https://www.acmicpc.net/problem/2468) 도전

## 문제 - 백준 2468

장마철에 내리는 비의 양에 따라 일정 높이 이하의 모든 지점은 물에 잠기게 되고, 물에 잠기지 않는 안전한 영역이 몇 개 있는지 구하는 문제입니다.
좀 더 자세하게 설명하자면:

- N×N 크기의 2차원 배열로 표현된 지역에서 각 요소는 해당 지역의 높이를 의미함
- 어떤 지역의 높이 이하에 비가 내리면 그 지역은 물에 잠김
- 물에 잠기지 않은 지역들이 상하좌우로 연결되어 있으면 하나의 안전한 영역을 이룸
- 모든 비의 양에 대해서 안전 영역의 최대 개수를 구해야 함

입출력 예:
| 입력 | 출력 |
| :-------- | :---------- |
| 5<br>6 8 2 6 2<br>3 2 3 4 6<br>6 7 3 3 2<br>7 2 5 3 6<br>8 9 5 2 7| 5 |
| 7<br>9 9 9 9 9 9 9<br>9 2 1 2 1 2 9<br>9 1 8 7 8 1 9<br>9 2 7 9 7 2 9<br>9 1 8 7 8 1 9<br>9 2 1 2 1 2 9<br>9 9 9 9 9 9 9| 6 |

## 접근 방식

### 첫 번째 도전(baekjoon-14495.cpp, baekjoon-14495.py)

1. 각 높이별로 물에 잠기는 지역을 계산하고, 안전 영역의 개수를 찾아야 함
2. 이중 반복문을 통해 지도의 모든 지점을 탐색하고, 물에 잠기지 않는 지점에서 DFS 또는 BFS를 시작
3. 한 번의 DFS/BFS로 하나의 안전 영역을 찾을 수 있으므로, DFS/BFS를 시작한 횟수가 안전 영역의 개수가 됨
4. 모든 가능한 높이(0부터 최대 높이까지)에 대해 시뮬레이션하여 가장 많은 안전 영역이 생기는 경우를 찾음

```
void dfs(int x, int y, int height) {
    visited[x][y] = true;

    // 4방향 탐색 (상, 우, 하, 좌)
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 맵 범위 내에 있고, 방문하지 않았으며, 높이가 기준 이상인 경우
        if (nx >= 0 && nx < N && ny >= 0 && ny < N &&
            !visited[nx][ny] && map[nx][ny] > height) {
            dfs(nx, ny, height);
        }
    }
}
```

```
def dfs(x, y, height):
    visited[x][y] = True

    # 4방향 탐색 (상, 우, 하, 좌)
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        # 맵 범위 내에 있고, 방문하지 않았으며, 높이가 기준 이상인 경우
        if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny] and area[nx][ny] > height:
            dfs(nx, ny, height)
```

## 배운 점

1. **DFS vs BFS**
   - DFS(깊이 우선 탐색, Depth-First Search)
     - 한 경로를 끝까지 탐색한 후 다음 경로로 넘어가는 방식
     - 마치 미로에서 한 길을 끝까지 가보고 막히면 돌아와서 다른 길을 시도하는 것과 유사
     - 재귀 또는 스택을 사용하여 구현
     - "깊게" 탐색하는 것이 핵심
   - BFS(너비 우선 탐색, Breadth-First Search)
     - 시작점에서 가까운 노드부터 차례대로 탐색하는 방식
     - 마치 물결이 퍼져나가듯이 중심에서부터 동심원 형태로 확장
     - 큐를 사용하여 구현
     - "넓게" 탐색하는 것이 핵심

**(핵심)** **DFS**는 **스택 / 재귀(LIFO)을 사용**해 "최근에 발견된 노드"부터 방문하여 **한 경로를 끝까지** 파고들고,
**BFS**는 **큐(FIFO)을 사용**해 "먼저 발견된 노드"부터 방문하여 **가까운 것부터 차례대로** 탐색합니다.
즉, **'어떤 자료구조로 노드를 꺼내느냐'(FIFO vs LIFO)**가 DFS/BFS를 구분짓는 가장 중요한 포인트입니다.

(코드 비교)
**DFS (재귀)**

```
# DFS (재귀 방식)
def dfs(x, y, height):
   visited[x][y] = True

   for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]

      if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny] and area[nx][ny] > height:
            dfs(nx, ny, height)  # 재귀 호출로 바로 깊이 탐색
```

**DFS (스택)**

```
// DFS (스택 방식)
void dfs_stack(int start_x, int start_y, int height) {
    stack<pair<int, int>> s;
    s.push({start_x, start_y});

    while (!s.empty()) {
        int x = s.top().first;
        int y = s.top().second;
        s.pop();

        // 이미 방문한 노드면 스킵
        if (visited[x][y])
            continue;

        // 방문 표시는 스택에서 꺼낼 때 함
        visited[x][y] = true;

        // 4방향 탐색 (탐색 순서가 중요하면 역순으로 스택에 추가)
        for (int i = 3; i >= 0; i--) {  // 3,2,1,0 순으로 스택에 추가하면 0,1,2,3 순으로 처리됨
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N &&
                !visited[nx][ny] && map[nx][ny] > height) {
                s.push({nx, ny});
            }
        }
    }
}
```

**BFS**

```
# BFS (덱 사용)
from collections import deque

def bfs(start_x, start_y, height):
   queue = deque([(start_x, start_y)])
   visited[start_x][start_y] = True

   while queue:
      x, y = queue.popleft()  # 큐에서 꺼내서 처리

      for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny] and area[nx][ny] > height:
               visited[nx][ny] = True
               queue.append((nx, ny))  # 큐에 넣고 나중에 처리
```

**(핵심)**

- DFS 재귀: 발견한 노드를 **즉시 처리**(재귀 호출)하므로 깊이 우선으로 탐색합니다.
- DFS 스택: 발견한 노드를 스택에 넣고, **가장 최근에 발견한 노드부터 처리**(LIFO)하므로 깊이 우선으로 탐색합니다.
- BFS: 발견한 노드를 큐에 넣고 **나중에 처리**하므로 너비 우선으로 탐색합니다.

2.  **DFS와 BFS 선택 가이드라인**
    그래프 탐색 문제에서 알고리즘 선택은 문제의 특성에 따라 달라집니다:

    - DFS(깊이 우선 탐색)가 적합한 경우:

      - **모든 경로**를 완전히 탐색해야 할때
      - 위상 정렬이 필요한 경우 (위상 정렬: 방향 그래프에서 노드 간의 선후관계를 지키는 순서로 노드를 정렬)
      - 사이클 탐지가 필요한 경우 (사이클: 그래프에서 시작 노드로 다시 돌아올 수 있는 경로로)
      - 그래프가 매우 넓을 때
      - 구현이 더 간단하며 재귀로 자연스럽게 표현 가능

    - BFS(너비 우선 탐색)가 적합한 경우:
      - **최단 경로**를 찾아야 할 때(동일 가중치 간선)
      - 시작점에서 가까운 순서대로 탐색해야 할 때
      - 레벨별 탐색이 필요할 때 (예: 특정 거리에 있는 모든 노드 찾기)
      - 두 노드 사이의 최소 이동 횟수를 구할 때
      - 양방향 탐색이나 다중 시작점 탐색

3.  **DFS를 활용한 연결 요소(Connected Component) 찾기**
    DFS는 그래프에서 연결된 요소를 찾는 데 매우 효과적인 알고리즘입니다. 이 문제에서는 물에 잠기지 않은 지역들 중 연결된 부분을 찾기 위해 활용했습니다.

4.  **방향 배열을 활용한 4방향 탐색**

    ```
    // 4방향 이동을 위한 배열 (상, 우, 하, 좌)
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    ```

    이 방식을 사용하면 4방향 탐색을 쉽게 구현할 수 있습니다. 각 인덱스는 상(x-1, y), 우(x, y+1), 하(x+1, y), 좌(x, y-1)를 나타냅니다.

5.  **시간 최적화 기법**

    ```
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ```

    이 코드는 C++ 입출력 성능을 향상시켜 실행 시간을 단축시키는 기법입니다. C++ 스트림과 C 스타일 입출력의 동기화를 끄고, cin/cout의 연결을 해제하여 속도를 개선합니다.

6.  **재귀 제한 설정 (Python)**

    ```
    import sys
    sys.setrecursionlimit(100000)
    ```

    Python은 기본 재귀 깊이 제한이 낮기 때문에, DFS를 재귀적으로 구현할 때 이 제한을 높여주어야 스택 오버플로우를 방지할 수 있습니다.

7.  **전체 시뮬레이션의 중요성**
    이 문제에서는 모든 가능한 높이에 대해 시뮬레이션을 해봐야 최대 안전 영역의 개수를 찾을 수 있습니다. 특정 높이에서만 확인하는 것이 아니라, 0부터 최대 높이까지 모든 경우를 확인해야 합니다.

8.  **Stack, Queue, Deque 특징**

    - **큐(Queue)**: FIFO(First In First Out) 방식

      - 데이터 추가: 맨 뒤에 추가 (enqueue)
      - 데이터 삭제: 맨 앞에서 삭제 (dequeue)
      - BFS 구현에 주로 사용됩니다

    - **스택(Stack)**: LIFO(Last In First Out) 방식

      - 데이터 추가: 맨 위(끝)에 추가 (push)
      - 데이터 삭제: 맨 위(끝)에서 삭제 (pop)
      - DFS 반복적 구현에 주로 사용됩니다

    - **덱(Deque)**: Double-Ended Queue

      - 양쪽 끝에서 모두 추가/삭제 가능
      - 앞쪽 추가/삭제: appendleft(), popleft()
      - 뒤쪽 추가/삭제: append(), pop()
      - 더 유연한 자료구조로, 상황에 따라 큐나 스택처럼 사용 가능
      - Python에서 BFS 구현 시 collections.deque를 주로 사용합니다
