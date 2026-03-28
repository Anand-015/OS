#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty;
int x = 0;
int buffer_size;

int wait(int s)
{
    return (--s);
}

int signal(int s)
{
    return (++s);
}

void producer() 
{
    mutex = wait(mutex);

    full = signal(full);
    empty = wait(empty);
    x++;

    printf("Producer produces item %d\n", x);

    mutex = signal(mutex);
}

void consumer()
{
    mutex = wait(mutex);

    full = wait(full);
    empty = signal(empty);

    printf("Consumer consumes item %d\n", x);
    x--;

    mutex = signal(mutex);
}

int main()
{
    int choice;

    printf("Enter buffer size: ");
    scanf("%d", &buffer_size);

    empty = buffer_size;

    printf("\n1. Produce\n2. Consume\n3. Exit\n");

    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if((mutex == 1) && (empty != 0))
                    producer();
                else
                    printf("Buffer is full\n");
                break;

            case 2:
                if((mutex == 1) && (full != 0))
                    consumer();
                else
                    printf("Buffer is empty\n");
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
