# 입력 받기
n = int(input())
area = []
max_height = 0

for _ in range(n):
    row = list(map(int, input().split()))
    area.append(row)
    max_height = max(max_height, max(row))

# 방향 배열 (상, 우, 하, 좌)
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

# 리스트를 스택처럼 활용한 DFS
def dfs(start_x, start_y, height):
    stack = [(start_x, start_y)]    # start_x, start_y는 값을 직접 수정할 일이 없으므로 튜플로 묶음
    visited[start_x][start_y] = True

    while stack:
        x, y =stack.pop()

        # 4방향 탐색
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]

            # 맵 범위 내에 있고, 방문하지 않았으며, 높이가 기준 이상인 경우
            if 0<=nx <n and 0<= ny <n and not visited[nx][ny] and area[nx][ny] >height:
                visited[nx][ny] = True
                stack.append((nx,ny))   # 스택에 추가

# 모든 가능한 높이에 대해 안전 영역 개수 계산
max_safe_area = 1  # 아무 지역도 물에 잠기지 않을 경우 안전 영역은 1개

for height in range(max_height):
    visited = [[False] * n for _ in range(n)]
    safe_area = 0
    
    # 모든 지역에 대해 DFS 수행
    for i in range(n):
        for j in range(n):
            if not visited[i][j] and area[i][j] > height:
                dfs(i, j, height)
                safe_area += 1  # 연결된 안전 영역 하나 발견
    
    # 최대 안전 영역 개수 갱신
    max_safe_area = max(max_safe_area, safe_area)

print(max_safe_area)