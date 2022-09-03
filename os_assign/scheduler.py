numb_of_cpu = int(input())
numb_of_proc = int(input())
arrival = list(map(int, input().split()))
burst = list(map(int, input().split()))

def fcfs(cpu, process, arrival, burst):
    arr = [[arrival[i], burst[i], i] for i in range(len(arrival))]
    arr.sort()
    cpus = ["" for i in range(cpu)]
    processors = [0 for i in range(cpu)]
    for i in range(process):
        j = processors.index(min(processors))
        s = str(arr[i][2] + 1)
        if arr[i][0] >= processors[j]:
            for k in range(arr[i][0] - processors[j]):
                cpus[j] += ' '
                processors[j] +=1
            for k in range(arr[i][1]):
                cpus[j] += s
                processors[j] +=1
            # processors[j] = arr[i][0] + arr[i][1]
        else:
            for i in range(arr[i][1]):
                processors[j] +=1
                cpus[j] += s
            # processors[j] += arr[i][1]
    for i in cpus:
        for j in i:
            print(j, end='')
        print('')
    
fcfs(numb_of_cpu, numb_of_proc, arrival, burst)

    

