# n: 날짜 수
# k: 연속 날짜 합
n, k = map(int, input().split())
temps = list(map(int, input().split()))

# 첫 k일 동안의 온도 합 계산
total = sum(temps[:k])
max_total = total

# 슬라이딩 윈도우 기법 적용
for i in range(n-k):
    # 새로운 합 = 이전 합 - 제외되는 값 + 새로 추가되는 값
    total = total - temps[i] + temps[i+k]
    max_total = max(max_total, total)

print(max_total)