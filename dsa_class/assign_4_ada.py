import random

from timeit import default_timer as timer 

random.seed(100)
li = []
n = int(input())
target = n * 1.5

def random_arr(n, li):
    for i in range(0, n):
        li.append(random.randrange(1, 2 * n))

def merge(li, left, mid, right):
    i = left
    j = mid + 1
    temp = []
    while i <= mid and j <= right:
        if li[i] <= li[j]:
            temp.append(li[i])
            i += 1
        else:
            temp.append(li[j])
            j += 1
    while i <= mid:
        temp.append(li[i])
        i += 1
    while j <= right:
        temp.append(li[j])
        j += 1
    for i in range(left, right + 1):
        li[i] = temp[i - left]

def merge_sort(li, l, r):
    if l == r:
        return
    mid = (l + r) // 2
    merge_sort(li, l, mid)
    merge_sort(li, mid + 1, r)
    merge(li, l, mid, r)

def insertion_sort(li):
    for i in range(1, len(li)):
        for j in range(i, 0, -1):
            if li[j] < li[j - 1]:
                li[j], li[j - 1] = li[j - 1], li[j]

def linear_search(li, target):
    for i in range(0, len(li)):
        if li[i] == target:
            return i
    return -1

def binary_search(li, target):
    l = 0
    r = len(li) - 1
    while (l <= r):
        mid = (l + r) // 2
        if (li[mid] == target):
            return mid
        if li[mid] > target:
            r = mid - 1
        else:
            l = mid + 1
    return -1
    
start = timer()
fullstart = start 

random_arr(n, li)
arr = li
insertion_sort(arr)
end = timer()
print ('Time for insertion sort: ', 1000 * (end - start), 'ms')
start = end
merge_sort(li, 0, len(arr) - 1)
end = timer()
print("Time for merge sort: ", 1000 * (end - start), 'ms')
start = end
print(linear_search(arr, target))
end = timer()
print("Time for linear search: ", 1000 * (end - start), 'ms')
start = end
print(binary_search(li, target))
end = timer()
print('Time for binary search: ', 1000 * (end - start), "ms")