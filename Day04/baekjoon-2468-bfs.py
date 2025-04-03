from collections import deque

n = int(input())
area = [[0]*n for _ in range(n)]
max_height =0

for i in range(n):
    row =list(map(int, input().split()))
    for j in range(n):
        area[i][j] = row[j]
    max_height=max(max(row), max_height)

# 방향 리스트
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

# dfs 함수 (재귀 방식)
# 1. 현재 노드가 이미 탐색한건지 아닌지 확인해야 한다.
# 2. 주어진 위치에 대하여 x, y 각각 4방향에 인접한 노드가 있는지 탐색한다.
#     (탐색할때, 맵 범위 안에 있고 방문하지 않았으며 높이가 기준을 넘어야 한다.)
def bfs(x,y,height):
    queue = deque([(x, y)])
    visited[x][y] = True

    while queue:
        x, y = queue.popleft()  # 큐에서 꺼내서 처리
        # 4방향 탐색
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]

            # 맵 범위 내에 있고, 방문하지 않았으며, 높이가 기준 이상인 경우
            if 0<=nx<n and 0<=ny<n and not visited[nx][ny] and area[nx][ny]>height:
                visited[nx][ny]= True
                queue.append((nx, ny))  # 큐에 넣고 나중에 처리

# 모든 가능한 높이에 대해 안전 영역 개수 계산
max_safe_area =1    # 아무 지역도 물에 잠기지 않은 경우 안전 영역은 1개


for height in range(max_height):
    visited = [[False]*n for _ in range(n)] # 1. 모든 height별로 방문했는지 안했는지 체크할 그래프를 만들 필요가 있다.
    safe_area =0    #  각 그래프별로 안전한 영역이라고 갯수센거 저장할 필요 있다.

    for i in range(n):
        for j in range(n):
            if not visited[i][j] and area[i][j] >height:
                bfs(i, j, height)
                safe_area +=1
    # 각 height별 safe_area가 최대인걸 비교를 해줘야 한다.
    max_safe_area = max(max_safe_area, safe_area)

print(max_safe_area)