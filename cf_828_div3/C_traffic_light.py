for _ in range(int(input())):
    n, c = input().split()
    n = int(n)
    s = input()
    s += s
    ocur = -1
    ans = 0
    for i in range(2 * n):
        v = s[i]
        if (v == c and ocur == -1) :
            ocur = i
        if (v == 'g' and ocur != -1):
            # print(i, ocur)
            ans = max(ans, i - ocur)
            ocur = -1
    print(ans)
