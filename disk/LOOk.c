#include<stdio.h>
#include<stdlib.h>

void sort(int arr[], int n){

    for(int i = 0; i < n - 1; i++){

        for(int j = i + 1; j < n; j++){

            if(arr[i] > arr[j]){

                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){

    int n, head;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];

    printf("Enter request sequence: ");

    for(int i = 0; i < n; i++){
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    int above[n], below[n];
    int a = 0, b = 0;

    // Split requests
    for(int i = 0; i < n; i++){

        if(req[i] >= head){
            above[a++] = req[i];
        }
        else{
            below[b++] = req[i];
        }
    }

    // Sort arrays
    sort(above, a);
    sort(below, b);

    int seek_time = 0;
    int current = head;

    printf("\nLOOK Head Movement\n%d", current);

    // Move right
    for(int i = 0; i < a; i++){

        seek_time += abs(current - above[i]);
        current = above[i];

        printf(" -> %d", current);
    }

    // Move left
    for(int i = b - 1; i >= 0; i--){

        seek_time += abs(current - below[i]);
        current = below[i];

        printf(" -> %d", current);
    }

    printf("\nSeek Time = %d", seek_time);

    return 0;
}