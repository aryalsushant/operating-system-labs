#include <stdio.h>

typedef struct Process {
    int pid;               // Process ID
    int arrival_time;      // Time process arrives
    int burst_time;        // Time required for execution
    int remaining_time;    // Remaining burst time (for preemptive algorithms)
    int completion_time;   // Time process finishes
    int waiting_time;      // Time spent waiting in ready queue
    int turnaround_time;   // Time from arrival to completion
} Process;

// 2. Scheduling Algorithm (Example: FCFS):
// For FCFS, processes are executed in the order of their arrival.
void fcfs_scheduling(Process processes[], int n) {
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        // Wait for process arrival if current_time is less than arrival_time
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }

        processes[i].completion_time = current_time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        current_time = processes[i].completion_time;
    }
}

// 3. Calculating Metrics:
// After scheduling, functions calculate and display average
// waiting time and average turnaround time.
void calculate_averages(Process processes[], int n) {
    float total_wait_time = 0;
    float total_turnaround_time = 0;

    for (int i = 0; i < n; i++) {
        total_wait_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("Average Waiting Time: %.2f\n", total_wait_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
}

int main() {
    int size = 3;
    Process ProcRA[size];

    printf("debug stmt: initializing ProcRA\n");

    ProcRA[0].pid = 1;
    ProcRA[1].pid = 2;
    ProcRA[2].pid = 3;

    ProcRA[0].arrival_time = 0;
    ProcRA[1].arrival_time = 0;
    ProcRA[2].arrival_time = 0;

    ProcRA[0].burst_time = 24;
    ProcRA[1].burst_time = 3;
    ProcRA[2].burst_time = 3;

    fcfs_scheduling(ProcRA, size);

    printf("debug stmt: back from call to fcfs\n");
    calculate_averages(ProcRA, size);
    printf("program done\n");

    return 0;
}
