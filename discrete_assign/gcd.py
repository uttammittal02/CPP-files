def __gcd(a, b):
    if (min(a, b) == 0):
        return max(a, b)
    return __gcd(min(a, b), max(a, b) % min(a, b))
for t in range(int(input())):
    a, b = [int(x) for x in input().split()]
    print(__gcd(a, b))