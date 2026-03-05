#include <stdio.h>

struct Process
{
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

int main()
{
    int n, i, j;
    float avg_waiting_time = 0,avg_turnaround_time=0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for(i = 0; i < n; i++)
    {
        p[i].pid=i+1;
        printf("Enter arrival time and burst time for Process %d\n",i+1 );
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
    }

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
     {
            if(p[i].arrival_time > p[j].arrival_time)
            {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    int current_time = 0;

    for(i = 0; i < n; i++)
    {
        if(current_time < p[i].arrival_time)
            current_time = p[i].arrival_time;

        current_time += p[i].burst_time;
        p[i].completion_time = current_time;
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;

        avg_waiting_time += p[i].waiting_time;
        avg_turnaround_time += p[i].turnaround_time;
    }



    avg_waiting_time /= n;
    avg_turnaround_time/=n;
    
   printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival_time,
               p[i].burst_time,
               p[i].completion_time,
               p[i].turnaround_time,
               p[i].waiting_time);
    }

    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
     printf("\nTurn around Time Time:     %.2f \n", avg_turnaround_time);
printf("GANTT CHART\n");
printf("\t");
 for(i=0;i<n;i++){
   printf( "P%d \t",p[i].pid);
    
 }
printf("\n");
printf("\n");
printf("0\t");

   for(i=0;i<n;i++){
  
     printf("   %d\t",p[i].completion_time);
 }
 
   
   

    return 0;
}




