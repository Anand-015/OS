#include<stdio.h>
int main(){
    int f,p,i,j,k;
    int fault,hit=0;
    int ref[100],fr[100];
    
    printf("enter the no of frames");
    scanf("%d",&f);
    printf("enter the no of pages");
    scanf("%d",&p);
    printf("enter the reference");
    for(i=0;i<p;i++){
        scanf("%d",&ref[i]);
    }
    for(i=0;i<f;i++){
       fr[i]=-1; 
    }
     int index=0;
     for(i=0;i<p;i++){
         int found=0;
         for(j=0;j<f;j++){
             if(ref[i]==fr[j]){
                 found=1;
                 hit++;
                 break;
             }
         }
         
        if(found==0){
            fr[index]=ref[i];
            index=(index+1)%f;
            fault++;
        }
        printf("\n");
        for(k=0;k<f;k++){
            printf("%d\t",fr[k]);
        }
     }
     printf("\nno of fault:%d",fault);
     printf("\nno of hit:%d",hit);
     return 0;
    
}