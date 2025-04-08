def count_pieces(arrangement):
    stack = []
    count = 0
    
    for i in range(len(arrangement)):
        if arrangement[i] == '(':
            stack.append('(')
        else:  # ')'인 경우
            stack.pop()  # 스택에서 짝이 되는 '(' 제거
            
            # 레이저인 경우 (바로 이전 문자가 '('이면)
            if arrangement[i-1] == '(':
                count += len(stack)  # 현재 스택에 있는 막대기 수만큼 조각 추가
            else:  # 막대기의 끝인 경우
                count += 1  # 막대기가 끝날 때 조각 1개 추가
    
    return count

# 입력 받기
arrangement = input().strip()
print(count_pieces(arrangement))