import sys
sys.setrecursionlimit(100000)  # 재귀 제한 높이기

islands=[]

# 방향 배열 (상, 우상, 우, 우하, 하, 좌하, 좌, 좌상) - 8방향 
dx = [-1, -1, 0, 1, 1, 1, 0, -1]
dy = [0, 1, 1, 1, 0, -1, -1, -1]

# DFS 함수
def dfs(x, y, island_exist):
    visited[x][y] = True
    
    # 8방향 탐색으로 수정
    for i in range(8):
        nx = x + dx[i]
        ny = y + dy[i]
        
        # 맵 범위 내에 있고, 방문하지 않았으며, 높이가 기준 이상인 경우
        if 0 <= nx < h and 0 <= ny < w and not visited[nx][ny] and current_map[nx][ny] == island_exist:
            dfs(nx, ny, island_exist)

while True:
    w, h = map(int, input().split())
    if w == 0 and h == 0:
        break
    
    # 현재 지도 데이터를 저장할 2차원 리스트
    current_map = []
    for i in range(h):
        row = list(map(int, input().split()))
        current_map.append(row)

    # 방문 여부 확인을 위한 리스트
    visited = [[False] * w for _ in range(h)]
    
    island_count = 0
    # 모든 지역에 대해 DFS 수행
    for i in range(h):
        for j in range(w):
            if not visited[i][j] and current_map[i][j] == 1:
                dfs(i, j, 1)
                island_count += 1
    
    print(island_count)


