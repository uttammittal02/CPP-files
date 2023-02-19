import math

for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]
    x , cnt = 1, 0
    while (x <= n):
        x *= 2
        cnt += 1
    x /= 2
    cnt -= 1
    pow = 0
    for i in a:
        while (not (i % 2)):
            i /= 2
            pow += 1
    ans = 0
    while (x > 1 and pow < n):
        ans += min(math.ceil((n // x) / 2), math.ceil((n - pow) / cnt));
        pow = min(n, pow + math.ceil((n // x) / 2) * cnt);
        x //= 2
        cnt -= 1
    if (pow >= n):
        print(ans)
    else:
        print(-1)
