numb_of_cpu = int(input())
numb_of_proc = int(input())
arrival = list(map(int, input().split()))
burst = list(map(int, input().split()))

def fcfs(cpu, process, arrival, burst):
    arr = [[arrival[i], burst[i]] for i in range(len(arrival))]
    arr.sort()
    
    # print(arr)
    
fcfs(numb_of_cpu, numb_of_proc, arrival, burst)
    
    

