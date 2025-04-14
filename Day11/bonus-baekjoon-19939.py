# n, k =map(int, input().split())

# basket =[0] * (k+1)

# for i in range(1,k+1):
#     basket[i] = i
#     n -=i

# if n<0:
#     print(-1)
# else:
#     while 0<n:
#         for i in range(k,0,-1):
#             basket[i] +=1
#             n-=1
#             if n==0:
#                 break

#     print(basket[k]-basket[1])

# 방법 2 - 등차수열
n, k = map(int, input().split())
ball = n - (k+1)*k//2

if ball< 0:
    print(-1)
else:
    # 공 6개 : 1,2,3 -> 2
    # 공 7개 : 1,2,4 -> 3
    # 공 8개 : 1,3,4 -> 3
    # 공 9개 : 2,3,4 -> 2
    if ball % k == 0:
        print(k-1)
    else:
        print(k)    