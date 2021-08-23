import itertools

for _ in range(int(input())):
    n, m, b = map(int, input().split())
    matrix = []
    permuterows = []
    permutecols = []
    for i in range(n):
        li = list(map(int, input().split()))
        matrix.append(li)
        permuterows.append(i)
    for i in range(m):
        permutecols.append(i)
    cnt = 0
    for i in range(1, n+1):
        for j in range(1, m+1):
            permrows = list(itertools.combinations(permuterows, i))
            permcols = list(itertools.combinations(permutecols, j))
            sum = 0
            # print(permrows, permcols)
            for x in permrows:
                for y in permcols:
                    sum = 0
                    for row in x:
                        for column in y:
                            sum += matrix[row][column]
                    if sum == b:
                        cnt += 1
    print(cnt)