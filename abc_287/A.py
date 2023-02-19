import numpy as np
cnt = 0
n = int(input())
for i in range(n):
    s = input()
    if (s == 'For'):
        cnt += 1
if cnt > n//2:
    print("Yes")
else:
    print("No")
    