#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

int buffer[SIZE];
int in = 0;
int out = 0;
int count = 0;
 void producer()
 {   
  int item;
  if(count == SIZE ||count >SIZE)
  {
   printf("Buffer is Full ");
   return;
  }
  printf("Enter item to produce: ");
  scanf("%d", &item);
  buffer[in] = item;
  in = (in + 1) % SIZE;
  count++;
  printf("Item produced: %d\n", item);
 }
void consumer()  
 {
  int item;
 if(count == 0)
 {
 printf("Buffer is Empty\n");
 return;
 }
 item = buffer[out];
 out = (out + 1) % SIZE;
 count--;
 printf("Item consumed: %d\n", item);
 }
 
int main()
 {
 int choice;
while(1)
{
printf("\n1. Produce\n2. Consume\n3. Exit\n");
printf("Enter choice: ");
scanf("%d", &choice);
switch(choice)
{
 case 1:
 producer();
 break;
 case 2:
 consumer();
 break;
 case 3:
 exit(0);
 default:
 printf("Invalid choice\n");
}
}
return 0;
}

