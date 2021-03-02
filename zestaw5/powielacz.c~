#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<semaphore.h>
#include"pthread.h"
#include"sem.h"
#include<string.h>

semid sem;

int main(int argc, char* argv[]){
   if(argc!=3){
       perror("Nieprawidlowe wywolanie\n");
       exit(EXIT_FAILURE);
    }
       sem = semOpen("sem");
       semInit(sem,1);
       int k = atoi(argv[2]);
       int i;
          for(i=0;i<k;i++){
             switch(fork()){
               case -1:
                  perror("Fork err\n");
                  exit(EXIT_FAILURE);
                  break;
               case 0:
                  execl(argv[1],(char*)NULL);
                default:
                  sleep(2);
                  wait(NULL);
               }
           }
         semRm(sem,"sem");
      return 0;
  }
