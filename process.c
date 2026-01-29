#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
int main(){
pid_t pid;
pid = fork();
if(pid<0){
perror("Fork failed");
return 1;
}
else if(pid ==0){
printf("child process:\n");
printf("Child PID : %d\n",getpid());
printf("Parent PID : %d\n",getppid());
}
else{
printf("parent process:\n");
printf("Parent PID : %d\n",getpid());
printf("Child PID : %d\n",pid);
sleep(5);
}
return 0;
}

