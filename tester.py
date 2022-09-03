n, m = 32, 23

s = set()
for i in range(1, n + 1):
    x = len(s)
    for j in range(1, m + 1):
        s.add(i ** j)
    # print(i, len(s) - x)
print(len(s))