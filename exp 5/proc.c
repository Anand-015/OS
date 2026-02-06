#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> 

int main() {
    pid_t pid;

    pid = fork(); 

    if (pid < 0) {
       
        perror("Fork failed");
        return 1;
    } 
    else if (pid == 0) {
     
        printf("PCCSL407 ");
    } 
    else {
       
        wait(NULL); 
        printf("Operating System lab\n");
    }
    
    return 0;
}
