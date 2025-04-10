num = int(input())
weights = list(map(int, input().split()))
weights.sort()  # 추들을 오름차순으로 정렬

# 현재까지 만들 수 있는 최대 연속 무게
target = 1

# 정렬된 추들을 하나씩 확인
for weight in weights:
    # 현재 추가 target보다 크면, target을 만들 수 없음
    if weight > target:
        break
    # 현재 추를 사용하면 target까지 모든 무게를 만들 수 있음
    # 다음에 확인해야 할 target은 지금까지 만들 수 있는 최대 무게 + 1
    target += weight

print(target)