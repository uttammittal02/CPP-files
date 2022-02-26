li = []
def subsets(arr, i, subset, x):
    global li
    if i == 6:
        a = subset.copy()
        if (len(subset) == x):
            li.append(a)
        # print(subset, li)
        return
    subsets(arr, i+1, subset, x)
    subset.append(arr[i])
    subsets(arr, i+1, subset, x)
    subset.pop()
    return

arr = [1, 2, 3, 4, 5, 6]
subsets(arr, 0, [], 2)
print("The combinations of length 2 with repitition not allowed are as follows :-")
print(*li)
subsets(arr, 0, [], 3)
print("The combinations of length 3 with repitition not allowed are as follows :-")
print(*li)
li = []
for i in range(1, 7):
    for j in range(1, 7):
        li.append([i, j])
print("The combinations of set 2 with repitition allowed are as follows :-")
print(*li)
li = []
for i in range(1, 7):
    for j in range(1, 7):
        for k in range(1, 7):
            li.append([i, j, k])
print("The combinations of set 3 with repitition allowed are as follows :-")
print(*li)

