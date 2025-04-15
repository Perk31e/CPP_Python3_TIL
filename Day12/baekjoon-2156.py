n = int(input())
wine = [0]  # 인덱스를 1부터 시작하기 위해 0번 인덱스에 0 추가
for _ in range(n):
    wine.append(int(input()))

# dp[i]는 i번째 와인까지 고려했을 때 최대로 마실 수 있는 포도주의 양
dp = [0] * (n + 1)

# 초기값 설정
if n >= 1:
    dp[1] = wine[1]
if n >= 2:
    dp[2] = wine[1] + wine[2]

# 점화식을 이용한 DP
for i in range(3, n + 1):
    # 세 가지 경우를 고려
    # 1. i번째 와인을 마시지 않는 경우: dp[i-1]
    # 2. i번째 와인과 i-1번째 와인을 마시고, i-2번째 와인을 마시지 않는 경우: dp[i-3] + wine[i-1] + wine[i]
    # 3. i번째 와인을 마시고, i-1번째 와인을 마시지 않는 경우: dp[i-2] + wine[i]
    dp[i] = max(dp[i-1], dp[i-3] + wine[i-1] + wine[i] if i >= 3 else 0, dp[i-2] + wine[i])

print(dp[n])