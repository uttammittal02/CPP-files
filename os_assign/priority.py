"""
Input Format:
job_count
cpu_count (processor_count)
For each process:
	process_name
	arrival_time, burst_time, priority
"""

from collections import deque
from functools import cmp_to_key

import matplotlib.pyplot as plt
import numpy as np
from distinctipy import distinctipy

def unique_color(n):
	# Get n distinct color
    return distinctipy.get_colors(n)

def average(a):
	return sum(a) / len(a);

def get_min_index(a):
	min_id = 0
	
	for i in range(len(a)):
		if a[i] < a[min_id]:
			min_id = i  
			
	return min_id 

def compare(x, y):
	if x[0] < y[0]:
		return -1
	elif x[0] > y[0]:
		return 1
	else:
		if x[2] < y[2]:
			return -1
		elif x[2] > y[2]:
			return 1 
		else:
			return 0
				 

if __name__ == "__main__":
	numb_of_jobs = int(input())
	numb_of_processors = int(input())
	
	jobs = []
	colors = unique_color(numb_of_jobs)
		
	for i in range(numb_of_jobs): 
		process_name = input()
		jobs.append([int(x) for x in input().split()] + [i])
	
	jobs.sort(key = cmp_to_key(compare))
	
	# Ready Queue
	priority_queue = deque()
	
	processor_state = [0 for i in range(numb_of_processors)]
	tat = [0 for i in range(numb_of_jobs)]
	wt = [0 for i in range(numb_of_jobs)]
	
	for i in range(numb_of_jobs):
		to_use = get_min_index(processor_state)
		
		start = max(processor_state[to_use], jobs[i][0])
		end = start + jobs[i][1] 
		
		plt.plot([start, end], [to_use, to_use], '-o', color = colors[i], label = jobs[i][3])
		
		processor_state[to_use] += jobs[i][1]
		tat[jobs[i][3]] = end
		wt[jobs[i][3]] = tat[jobs[i][3]] - jobs[i][1]
		
		plt.legend()
	
	plt.grid(axis = 'x', color = 'black', linestyle = '--', linewidth = '0.4')
	plt.title(f"Priority Scheduling Algo\nTurn Around Time: {tat}\nWaiting Time: {wt}\nAverage Turn Around Time: {average(tat)}\nAverage Waiting Time: {average(wt)}")
	plt.show()