stack=[]

# 방향 배열 (상, 우상, 우, 우하, 하, 좌하, 좌, 좌상) - 8방향 
dx = [-1, -1, 0, 1, 1, 1, 0, -1]
dy = [0, 1, 1, 1, 0, -1, -1, -1]

def dfs(start_x, start_y):
    stack=[(start_x, start_y)]
    visited[start_x][start_y]=True

    while stack:
        x, y = stack.pop()

        for i in range(8):
            nx = x+dx[i]
            ny = y+dy[i]

            if 0<= nx < h and 0<=ny<w and not visited[nx][ny] and current_map[nx][ny]==1:
                stack.append((nx, ny))
                visited[nx][ny]=True

while(True):
    w, h = map(int, input().split())
    current_map=[]
    if w==0 and h==0:
        break

    # map 입력 받기
    for i in range(h):
        row = list(map(int, input().split()))[:w]
        current_map.append(row)

    # 방문여부 확인 리스트 준비
    visited = [[False]*w for _ in range(h)]

    island_count =0

    # 모든 지역에 대해 DFS 수행
    for i in range(h):
        for j in range(w):
            if not visited[i][j] and current_map[i][j] == 1:
                dfs(i, j)
                island_count += 1
    

    print(f"{island_count}")
