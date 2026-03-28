#include<stdio.h>

int main(){
    int n,i,qt;
    int p[10],at[10],bt[10],rt[10],ct[10],tat[10],wt[10];
    int time=0,remain;
    float avg_wt,avg_tat=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    // Input
    for(i=0;i<n;i++){
        printf("Enter AT and BT for P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
        rt[i]=bt[i];
        p[i]=i+1;// remaining time
    }

    printf("Enter time quantum: ");
    scanf("%d",&qt);

    remain = n;

    // Round Robin Logic
    while(remain > 0){
        for(i=0;i<n;i++){

            if(rt[i] > 0 && at[i] <= time){

                if(rt[i] > qt){
                    time += qt;
                    rt[i] -= qt;
                }
                else{
                    time += rt[i];
                    ct[i] = time;
                    rt[i] = 0;
                    remain--;
                }
            }
        }
    }

    // Calculate TAT and WT
    for(i=0;i<n;i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avg_wt+=wt[i];
        avg_tat+=tat[i];
    }

    // Output
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("AVG TAT:%.2f",avg_tat/n);
    printf("AVG WT:%.2f",avg_wt/n);
    
    printf("\nGANTT CHART\n");
    for(i=0;i<n;i++){
        printf("P%d\t",p[i]);
    }
    printf("\n");
    printf("0\t");
    for(i=0;i<n;i++){
        printf("%d\t",ct[i]);
    }
    return 0;
}