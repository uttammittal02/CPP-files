n = int(input())
li = list(map(int, input().split()))
q = int(input())
lix = list(map(int, input().split()))
sum_ = sum(li)
for i in range(q):
    sum_*=2
    print(int(sum_%(1e9 + 7)))
