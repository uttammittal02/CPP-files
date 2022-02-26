print("Welcome\nWe're gonna deal with the following compound statement today:\n ((p^q)^r) -> (sVt)\n ")
# p, q, r, s, t = [int(x) for x in input().split()]
print('p q r s t boolean')
for p in range(2):
    for q in range(2):
        for r in range(2):
            for s in range(2):
                for t in range(2):
                    ans = bool((not((p & q) & r)) or (s or t))
                    print(p, q, r, s, t, int(ans))
