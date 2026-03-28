#include<stdio.h>
int main(){
    int f,p,i,j,k;
    int fault=0,hit=0;
    int ref[100],fr[100],time[100];
    
    printf("enter the no of frames: ");
    scanf("%d",&f);

    printf("enter the no of pages: ");
    scanf("%d",&p);

    printf("enter the reference: ");
    for(i=0;i<p;i++){
        scanf("%d",&ref[i]);
    }

    // initialize frames and time
    for(i=0;i<f;i++){
        fr[i] = -1;
        time[i] = 0;
    }

    int count = 0;

    for(i=0;i<p;i++){
        int found = 0;

        // check HIT
        for(j=0;j<f;j++){
            if(ref[i] == fr[j]){
                found = 1;
                hit++;
                count++;
                time[j] = count;   // update recent use
                break;
            }
        }

        // if FAULT
        if(found == 0){
            int min = 0;

            // find least recently used
            for(j=1;j<f;j++){
                if(time[j] < time[min]){
                    min = j;
                }
            }

            fr[min] = ref[i];
            count++;
            time[min] = count;
            fault++;
        }

        // display frames
        printf("\n");
        for(k=0;k<f;k++){
            printf("%d\t",fr[k]);
        }
    }

    printf("\nno of fault:%d",fault);
    printf("\nno of hit:%d",hit);

    return 0;
}