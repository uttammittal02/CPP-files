"""
Input Format:
job_count
cpu_count (processor_count)
For each process:
	process_name
	arrival_time, burst_time
"""

from collections import deque

import matplotlib.pyplot as plt
import numpy as np
from distinctipy import distinctipy

def unique_color(n):
	# Get n distinct color
    return distinctipy.get_colors(n)

def average(a):
	return sum(a) / len(a);

def get_min_index(a):
	min_ = 0
	
	for i in range(len(a)):
		if a[i] < a[min_]:
			min_ = i  
			
	return min_ 


if __name__ == "__main__":
	number_of_jobs = int(input())
	number_of_cpus = int(input())
	
	jobs = []
	colors = unique_color(number_of_jobs)
		
	for i in range(number_of_jobs): 
		process_name = input()
		jobs.append([int(x) for x in input().split()] + [i])
		
	# Ready Queue
	q = deque()
	
	processor_state = [0 for i in range(number_of_cpus)]
	tat = [0 for i in range(number_of_jobs)]
	wt = [0 for i in range(number_of_jobs)]
	
	for i in range(number_of_jobs):
		to_use = get_min_index(processor_state)
		
		start = max(processor_state[to_use], jobs[i][0])
		end = start + jobs[i][1] 
		
		plt.plot([start, end], [to_use, to_use], '-o', color = colors[i], label = jobs[i][2])
		
		processor_state[to_use] += jobs[i][1]
		tat[jobs[i][2]] = end
		wt[jobs[i][2]] = tat[jobs[i][2]] - jobs[i][1]
		
		plt.legend()
	
	plt.grid(axis = 'x', color = 'black', linestyle = '--', linewidth = '0.4')
	plt.title(f"Shortest Job First Algo\nTurn Around Time: {tat}\nWaiting Time: {wt}\nAverage Turn Around Time: {average(tat)}\nAverage Waiting Time: {average(wt)}")
	plt.show()