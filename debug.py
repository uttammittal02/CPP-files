n = 123456789
while n:
    s = n
    ans = 0
    while s:
        ans = max(ans, s%10)
        s //= 10
    n -= ans
    if (n > 123456700):
        print(n)
# 1 2 3 4 5
