#include<stdio.h>
#include<stdlib.h>
void sort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
int main(){
    int head,n,size;
    printf("enter the no of req");
    scanf("%d",&n);
    int req[n];
    printf("enter the req");
    for(int i=0;i<n;i++){
        scanf("%d",&req[i]);
    }
    printf("enter the head  and size");
    scanf("%d%d",&head,&size);
    
    int seek_time=0;
    int current=head;
    
    printf("HEAD movement \n%d",current);
    int above[n],below[n];
    int a=0,b=0;
    
    for(int i=0;i<n;i++){
        if(req[i]>=head){
            above [a++]=req[i];
        }
        else{
            below[b++]=req[i];
        }
        }
        
        sort(above,a);
        sort(below,b);
        
        for(int i=0;i<a;i++){
            seek_time+=abs(current-above[i]);
            current=above[i];
            printf("-> %d",current);
        }
        if(b>0){
            
            seek_time+=abs(current-(size-1));
            current=size-1;
            printf("-> %d",current);
            
            seek_time+=(size-1);
            current=0;
            printf("-> %d",current);
            
            for(int i=0;i<b;i++){
                seek_time+=abs(current-below[i]);
                current=below[i];
                printf("-> %d",current);
            
        }
        printf("\n SK = %d",seek_time);
        return 0;
}
}