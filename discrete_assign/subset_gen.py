# import plotly.express as px
li = []
def subsets(arr, i, subset):
    global li
    if i == len(arr):
        a = subset.copy()
        li.append(a)
        # print(subset, li)
        return
    subsets(arr, i+1, subset)
    subset.append(arr[i])
    subsets(arr, i+1, subset)
    subset.pop()
    return

n = int(input())
arr = [int(x) for x in range(1, n+1)]
subsets(arr, 0, [])
print(*li)
