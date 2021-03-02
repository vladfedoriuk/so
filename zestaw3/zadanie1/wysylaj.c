#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>


int main( int argc, char*argv[]){
 if(argc<=2){
   perror("Nieprawidlowe urochomiene\n");
   exit(EXIT_FAILURE);
  } 
     int pid;
     switch((pid=fork())){
       case -1:
         perror("Fork error\n");
         exit(EXIT_FAILURE);
         break;
       case 0:
         execl("./obsluga.x", "obsluga.x", argv[1], argv[2], NULL);
         break;
       default:
           sleep(1);
           kill(pid,0);
           kill(pid,atoi(argv[2]));
           perror("kill sie wykonal\n");
           break;
    }
 wait(NULL);
 return 0;
}
