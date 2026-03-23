#include <stdio.h>

// Function to print frames
void printFrames(int f[], int frames){
    for(int i = 0; i < frames; i++){
        if(f[i] == -1)
            printf("-\t");
        else
            printf("%d\t", f[i]);
    }
}

// FIFO Algorithm
void FIFO(int pages[], int n, int frames){
    int f[frames], faults = 0, pos = 0;

    for(int i = 0; i < frames; i++)
        f[i] = -1;

    printf("\nPage\t");
    for(int i = 0; i < frames; i++) printf("F%d\t", i+1);
    printf("Status\n");

    for(int i = 0; i < n; i++){
        int found = 0;

        for(int j = 0; j < frames; j++){
            if(f[j] == pages[i]){
                found = 1;
                break;
            }
        }

        printf("%d\t", pages[i]);

        if(found){
            printFrames(f, frames);
            printf("H\n");
        } else {
            f[pos] = pages[i];
            pos = (pos + 1) % frames;
            faults++;

            printFrames(f, frames);
            printf("M\n");
        }
    }

    printf("Total Page Faults = %d\n", faults);
}

// LRU Algorithm
void LRU(int pages[], int n, int frames){
    int f[frames], time[frames];
    int faults = 0, count = 0;

    for(int i = 0; i < frames; i++){
        f[i] = -1;
        time[i] = -1;
    }

    printf("\nPage\t");
    for(int i = 0; i < frames; i++) printf("F%d\t", i+1);
    printf("Status\n");

    for(int i = 0; i < n; i++){
        int found = 0;

        for(int j = 0; j < frames; j++){
            if(f[j] == pages[i]){
                count++;
                time[j] = count;
                found = 1;
                break;
            }
        }

        printf("%d\t", pages[i]);

        if(found){
            printFrames(f, frames);
            printf("H\n");
        } else {
            int pos = -1;

            // Check for empty frame first
            for(int j = 0; j < frames; j++){
                if(f[j] == -1){
                    pos = j;
                    break;
                }
            }

            // If no empty frame, find LRU
            if(pos == -1){
                int min = time[0];
                pos = 0;
                for(int j = 1; j < frames; j++){
                    if(time[j] < min){
                        min = time[j];
                        pos = j;
                    }
                }
            }

            f[pos] = pages[i];
            count++;
            time[pos] = count;
            faults++;

            printFrames(f, frames);
            printf("M\n");
        }
    }

    printf("Total Page Faults = %d\n", faults);
}

// Optimal Algorithm
void OPTIMAL(int pages[], int n, int frames){
    int f[frames], faults = 0;

    for(int i = 0; i < frames; i++)
        f[i] = -1;

    printf("\nPage\t");
    for(int i = 0; i < frames; i++) printf("F%d\t", i+1);
    printf("Status\n");

    for(int i = 0; i < n; i++){
        int found = 0;

        for(int j = 0; j < frames; j++){
            if(f[j] == pages[i]){
                found = 1;
                break;
            }
        }

        printf("%d\t", pages[i]);

        if(found){
            printFrames(f, frames);
            printf("H\n");
        } else {
            int pos = -1, farthest = -1;

            // Check for empty frame first
            for(int j = 0; j < frames; j++){
                if(f[j] == -1){
                    pos = j;
                    break;
                }
            }

            // If no empty frame, apply optimal logic
            if(pos == -1){
                for(int j = 0; j < frames; j++){
                    int next = -1;

                    for(int k = i + 1; k < n; k++){
                        if(f[j] == pages[k]){
                            next = k;
                            break;
                        }
                    }

                    // If page not used again
                    if(next == -1){
                        pos = j;
                        break;
                    }

                    // Choose farthest use
                    if(next > farthest){
                        farthest = next;
                        pos = j;
                    }
                }
            }

            f[pos] = pages[i];
            faults++;

            printFrames(f, frames);
            printf("M\n");
        }
    }

    printf("Total Page Faults = %d\n", faults);
}

// Main Function
int main(){
    int n, frames, choice;
    int pages[50];

    printf("Enter reference string length (max 50): ");
    scanf("%d", &n);

    if(n <= 0 || n > 50){
        printf("Invalid length\n");
        return 0;
    }

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    if(frames <= 0){
        printf("Invalid frame count\n");
        return 0;
    }

    printf("Enter page reference string:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &pages[i]);
    }

    while(1){
        printf("\n1. FIFO\n2. LRU\n3. Optimal\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: FIFO(pages, n, frames); break;
            case 2: LRU(pages, n, frames); break;
            case 3: OPTIMAL(pages, n, frames); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
}