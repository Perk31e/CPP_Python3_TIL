N, M = map(int, input().split())

# 체스판의 세로, 가로 길이가 작은 경우
if N == 1:
    print(1)
elif N == 2:
    print(min(4, (M + 1) // 2))
else:
    if M < 7:
        # 4가지 이동 방식 모두 사용 불가능한 경우
        print(min(4, M))
    else:
        # 4가지 이동 방식을 모두 사용할 수 있는 경우
        print(M - 2)