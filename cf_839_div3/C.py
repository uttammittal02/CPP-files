st = 1 
diff = 1
li = [1 for x in range(40)]
for i in range(40):
    li[i] = st
    st += diff
    diff += 1
for _ in range(int(input())):
    a = [int(x) for x in input().split()]
    k = a[0]
    n = a[1]
    arr = li[:k]
    for i in range(k-1, 0, -1):
        arr[i] = min(n, arr[i])
        n-=1
    print(*arr)
