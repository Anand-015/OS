#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, head;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n], visited[n];

    printf("Enter request sequence: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
        visited[i] = 0;
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    int total_seek = 0;
    int current = head;

    printf("\nSSTF Head Movement:\n%d", current);

    for(int i = 0; i < n; i++) {

        int min = 100000;
        int index = -1;

        for(int j = 0; j < n; j++) {

            if(!visited[j]) {

                int dist = abs(current - req[j]);

                if(dist < min) {
                    min = dist;
                    index = j;
                }
            }
        }

        visited[index] = 1;
        total_seek += min;
        current = req[index];

        printf(" -> %d", current);
    }

    printf("\nTotal Seek Time = %d\n", total_seek);

    return 0;
}