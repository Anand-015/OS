#include <stdio.h>

int main() {
    int frames, pages, i, j, k;
    int fault = 0, hit = 0;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int ref[50], frame[10];

    printf("Enter reference string: ");
    for(i = 0; i < pages; i++)
        scanf("%d", &ref[i]);

    for(i = 0; i < frames; i++)
        frame[i] = -1;

    for(i = 0; i < pages; i++) {
        int found = 0;

        for(j = 0; j < frames; j++) {
            if(frame[j] == ref[i]) {
                found = 1;
                hit++;                
                break;
            }
        }

        if(found==0){
            int pos=-1,fur=-1;
            for(j=0;j<frames;j++){
                int k;
                for(k=i+1;k<pages;k++){
                    if(frame[j]==ref[k])
                    break;
                }
                if(k==pages){
                    pos=j;
                    break;
                }
                if(k>fur){
                    fur=k;
                    pos=j;
                }
                
            }
            frame[pos]=ref[i];
            fault++;
        }

        printf("\n");
        for(k = 0; k < frames; k++)
            printf("%d\t", frame[k]);
    }

    printf("\n\nTotal Page Faults = %d", fault);
    printf("\nTotal Page Hits = %d\n", hit);

    return 0;
}
