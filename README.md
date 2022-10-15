# Assignment 4

* Authors: Samuel Bernsen, Max Starreveld
* Student ID: 2367195
* CPSC 380
* Assignment 4

Source files:
* cpu.c
* cpu.h
* driver.c
* list.c
* list.h
* Makefile
* queue.c
* queue.h
* schedule_fcfs.c
* schedule_priority.c
* schedule_rr.c
* schedule_sjf.c
* schedule.txt
* schedulers.h
* task.h

references:

- Lucas Gaudet

Running the program:

1. to build for the specified scheduling algorithm, execute the command:

    <code>make \<scheduling algorithm\></code>
    
    where \<scheduling algorithm\> is the name of the scheduling algorithm you want to run. 
    Options include:
    - priority
    - sjf
    - fcfs
    - rr
    - priority_rr
2. to run the program, execute the command:
    
    <code>./\<scheduling algorithm\> schedule.txt</code>

    where schedule.txt is a test file with processes to 
    schedule in the format: task name, priority, burst time.

Sample output:

    Running task = [T8] [10] [25] for 10 units.
    Running task = [T5] [5] [20] for 5 units.
    Running task = [T4] [5] [15] for 5 units.
    Running task = [T1] [4] [20] for 4 units.
    Running task = [T7] [3] [30] for 3 units.
    Running task = [T3] [3] [25] for 3 units.
    Running task = [T2] [3] [25] for 3 units.
    Running task = [T6] [1] [10] for 1 units.
