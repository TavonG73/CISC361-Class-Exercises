#include <stdio.h>
#include <stdbool.h>

int main() {
    // Initialize variables
    int i = 0, num_processes = 0, total_time = 0, x, output_flag = 0, time_quantum = 0;
    int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10], turnaround[10], waiting[10];
    float average_wait_time = 0, average_turnaround_time = 0;
    bool round_robin_algorithm = false;
    for(i=0; i<10; i++) {
        arrival_time[i] = 0;
        burst_time[i] = 0;
        temp[i] = 0;
    }
    
    // Define number of processes
    while(num_processes < 1 || num_processes > 10) {
        printf("\nEnter total number of processes (1 - 10):\t");
        scanf("%d", &num_processes);
        if(num_processes < 1 || num_processes > 10) {
            printf("Incorrect value entered");
        }
    }
    // Define process details
       x = num_processes;
       for(int i=0; i<num_processes; i++) {
           printf("\nEnter details of process[%d]\n", i+1);
           printf("Arrival time (>-1):\t");
           scanf("%d", &arrival_time[i]);

           printf("Burst time (>0):\t");
           scanf("%d", &burst_time[i]);
           temp[i] = burst_time[i];

           if(arrival_time[i] < 0 && burst_time[i] < 1) {
               printf("Incorrect values entered");
               i--;
           }
       }
    // Define quantum
        if(round_robin_algorithm) {
            while(time_quantum < 1) {
                printf("\nEnter time quantum (>0):\t");
                scanf("%d", &time_quantum);
                if(time_quantum < 1) {
                    printf("Incorrect value entered");
                }
            }
        }

        // Prepare output
        printf("\nProcess ID\t\tArrival Time\t\tBurst Time\t\tTurnaround Time\t\tWaiting Time\n");

        // Perform Scheduling Calculations
        if(!round_robin_algorithm) {

            // Sorts arrival and burst times
            for(int i=0; i<num_processes; i++) {
                int tmp = 0;
                int tmp2;
                for(int j=i+1; j<num_processes; j++) {
                    if(arrival_time[i] > arrival_time[j]) {
                        tmp = arrival_time[i];
                        arrival_time[i] = arrival_time[j];
                        arrival_time[j] = tmp;
                        tmp2 = burst_time[i];
                        burst_time[i] = burst_time[j];
                        burst_time[j] = tmp2;
                    }
                }
            }

