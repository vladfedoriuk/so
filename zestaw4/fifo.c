#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<limits.h>
#include<string.h>

int main(){
 if(mkfifo("./potok",0666)==-1){
    perror("Mkfifo error\n");
    exit(EXIT_FAILURE);
  }
int fd;
 switch(fork()){
    case -1:
       perror("Fork error\n");
       exit(EXIT_FAILURE);
       break;
    case 0:
       execl("./producent.x","producent.x", "./potok",(char*)NULL);
    default:
        if((fd=open("./potok",O_RDONLY|O_CREAT,0666))==-1){
             perror("Nie udalo sie otworzyc potok do czytania");
             exit(EXIT_FAILURE);
           } 
       sleep(10);   
       wait(NULL);
       break;
 }
  switch(fork()){
    case -1:
       perror("Fork error\n");
       exit(EXIT_FAILURE);
       break;
    case 0:
       execl("./konsument.x","konsument.x", "./potok",(char*)NULL);
    default:
       if((fd=open("./potok",O_WRONLY|O_CREAT,0666))==-1){
             perror("Nie udalo sie otworzyc potok do zapisywania");
             exit(EXIT_FAILURE);
           }  
       sleep(10);
       close(fd);
       wait(NULL);
       break;
 }
   unlink("./potok");
   return 0;
}
 
 
