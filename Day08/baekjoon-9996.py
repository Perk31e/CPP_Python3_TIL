num=int(input())
target=[]
for i in range(num+1):
    s=input().strip()
    target.append(s)

# target[0] 내 저장된 문자열에서 *을 중심으로 앞, 뒤를 나눈다.

# 1. 먼저 *을 찾는다.
star_idx=target[0].find('*')
front = target[0][:star_idx]
back = target[0][star_idx+1:]

for i in range(1,num+1):
    if len(target[i]) >= len(front) + len(back):
        if target[i][:len(front)] == front and target[i][len(target[i])-len(back):] == back:
            print("DA")
        else:
            print("NE")
    else:
        print("NE")