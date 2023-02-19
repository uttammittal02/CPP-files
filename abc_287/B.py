# import numpy as np
n, m = [int(x) for x in input().split()]
li = []
for _ in range(n):
    li.append(input())
s = set()
for _ in range(m):
    s.add(input())
ans = 0
for i in range(n):
    if li[i][3:] in s:
        ans += 1
print(ans)