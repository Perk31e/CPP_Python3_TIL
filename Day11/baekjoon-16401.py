n, m = map(int, input().split())
snacks = list(map(int, input().split()))

# 가능한 과자의 최소 길이는 1, 최대 길이는 가장 긴A 과자의 길이
start = 1
end = max(snacks)
result = 0

# 이진 탐색
while start <= end:
    mid = (start + end) // 2
    
    # 과자의 길이가 mid일 때 몇 명에게 나눠줄 수 있는지 계산
    count = 0
    for snack in snacks:
        count += snack // mid  # 각 과자를 mid 길이로 몇 개 나눌 수 있는지
    
    # 조카 수보다 많거나 같은 수의 과자를 만들 수 있으면
    if count >= n:
        result = mid  # 현재 길이를 저장
        start = mid + 1  # 더 긴 길이로 시도
    else:
        end = mid - 1  # 더 짧은 길이로 시도

print(result)