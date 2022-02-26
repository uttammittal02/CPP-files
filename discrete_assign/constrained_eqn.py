li = []
for i in range(10):
    for j in range(i, 10):
        for k in range(j, 10):
            if (i + j + k == 10):
                li.append([i, j, k])
                break
for i in li:
    print(i)