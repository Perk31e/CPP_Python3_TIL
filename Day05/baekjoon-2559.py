# n: 날짜 수
# k: 연속 날짜 합
n, k = map(int, input().split())
temps = list(map(int, input().split()))
result =[]
total=0

#전체 n일 중 k 일씩 뽑아서 온도합을 비교하여 제일 온도가 높은때를 출력하라
for days in range(n):
    
    if (days+k) <= len(temps):
        for temp in range(days, days+k):
            total+=temps[temp]
        result.append(total)
    total=0

print(max(result))