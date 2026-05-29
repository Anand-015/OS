#include <stdio.h> 
 
int main() { 
    int r, c; 
 
    printf("Enter number of processes: "); 
    scanf("%d", &r);  // rows = processes 
 
    printf("Enter number of resources: "); 
    scanf("%d", &c);  // columns = resources 
 
    int alloc[r][c], max[r][c], need[r][c]; 
    int avail[c], work[c], finish[r], safe[r]; 
 
    // Input Allocation Matrix 
    printf("Enter Allocation Matrix:\n"); 
    for(int i = 0; i < r; i++) 
        for(int j = 0; j < c; j++) 
            scanf("%d", &alloc[i][j]); 
 
    // Input Max Matrix 
    printf("Enter Max Matrix:\n"); 
    for(int i = 0; i < r; i++) 
        for(int j = 0; j < c; j++) 
            scanf("%d", &max[i][j]); 
 
    // Need = Max - Allocation 
    for(int i = 0; i < r; i++) 
        for(int j = 0; j < c; j++) 
            need[i][j] = max[i][j] - alloc[i][j]; 
 
    // Input Available Resources 
    printf("Enter Available Resources:\n"); 
    for(int j = 0; j < c; j++) { 
        scanf("%d", &avail[j]); 
        work[j] = avail[j]; 
    } 
 
    // Initialize finish array 
    for(int i = 0; i < r; i++) 
        finish[i] = 0; 
 
    int count = 0; 
 
    while(count < r) { 
        int found = 0; 
 
        for(int i = 0; i < r; i++) { 
            if(finish[i] == 0) { 
                int flag = 1; 
 
                // Check if process can be satisfied 
                for(int j = 0; j < c; j++) { 
                    if(need[i][j] > work[j]) { 
                        flag = 0; 
                        break; 
                    } 
                } 
 
                if(flag) { 
                    // Allocate resources 
                    for(int j = 0; j < c; j++) 
                        work[j] += alloc[i][j]; 
 
                    safe[count++] = i; 
                    finish[i] = 1; 
                    found = 1; 
                } 
            } 
        } 
 
        if(found == 0) { 
            printf("System is NOT safe\n"); 
            return 0; 
        } 
    } 
 
    printf("Safe sequence: "); 
    for(int i = 0; i < r; i++) 
        printf("P%d ", safe[i]); 
 
    printf("\n"); 
 
    return 0; 
} 
} 
