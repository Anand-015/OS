#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,i,j;
    int p[10],at[10],bt[10],ct[10],tat[10],wt[10];
    int time=0,temp;
    float avg_wt,avg_tat=0;
    
    printf("enter the no.of proess");
    scanf("%d",&n);
     for(i=0;i<n;i++){
         printf("enter the arrival time and burst time : \n");
         scanf("%d%d",&at[i],&bt[i] );
         p[i]=i+1;}
         
         for(i=0;i<n;i++){
             for(j=i+1;j<n;j++){
                 if(at[i]>at[j]){
                     temp=at[i];
                     at[i]=at[j];
                     at[j]=temp;
                     
                     temp=bt[i];
                     bt[i]=bt[j];
                     bt[j]=temp;
                     
                     temp=p[i];
                     p[i]=p[j];
                     p[j]=temp;
                     
                     
                 }
                 
             }
         }
         for(i=0;i<n;i++){
         if(time<at[i])
         time=at[i];
         
         time=time+bt[i];
         ct[i]=time;
         
         tat[i]=ct[i]-at[i];
         wt[i]=tat[i]-bt[i];
         
         avg_tat=avg_tat+tat[i];
         avg_wt=avg_wt+wt[i];}
         
         printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
         for(i=0;i<n;i++){
             printf("\n%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);}
             
             printf("\navg TAT:%.2f",avg_tat/n);
             printf("\n avg wt:%.2f",avg_wt/n);
             
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