def solution(wallpaper):
    location =[]
    for i in range(len(wallpaper)):
        for j in range(len(wallpaper[i])):
            if wallpaper[i][j] == '.':
                continue
            if wallpaper[i][j] == '#':
               location.append((i, j))
    
    answer = []
    small_x = min(loc[0] for loc in location)
    small_y = min(loc[1] for loc in location)
    large_x = max(loc[0] for loc in location) + 1
    large_y = max(loc[1] for loc in location) + 1
    answer.append(small_x)
    answer.append(small_y)
    answer.append(large_x)    
    answer.append(large_y)
    return answer