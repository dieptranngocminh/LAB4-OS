sched_fcfs: queue.o sched_fcfs.o
	gcc -pthread queue.o sched_fcfs.o -o sched_fcfs
queue.o: queue.h queue.c
	gcc -pthread -c queue.c -o queue.o
sched_fcfs.o: sched_fcfs.c structs.h
	gcc -pthread -c sched_fcfs.c -o sched_fcfs.o

sched_rr: queue.o sched_rr.o
	gcc -pthread queue.o sched_rr.o -o sched_rr
queue.o: queue.h queue.c
	gcc -pthread -c queue.c -o queue.o
sched_rr.o: sched_rr.c structs.h
	gcc -pthread -c sched_rr.c -o sched_rr.o

run_fcfs:
	@echo "Input file:"
	@cat input.txt
	@echo "Results"
	@cat input.txt | ./sched_fcfs
run_rr:
	@echo "Input file:"
	@cat input.txt
	@echo "Results"
	@cat input.txt | ./sched_rr
clean:
	rm -f *.o sched_fcfs sched_rr
