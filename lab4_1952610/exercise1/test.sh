#!/bin/bash
echo "Input file:"
cat input.txt
echo "Results"
gcc sched_fcfs.c queue.c -o sched_fcfs -lpthread
cat input.txt | ./sched_fcfs
