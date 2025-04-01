n = int(input())
arr = [0]*n
for i in range(n):
    if i <=2:
        arr[i]=1
    elif i>2:
        arr[i]=arr[i-1]+arr[i-3]

print(arr[n-1])