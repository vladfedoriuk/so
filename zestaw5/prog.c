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
       int set = time(NULL);
       srand(set);
       sem = semOpen("sem");
         printf("proces o pid = %d podnosi semafor\n",getpid());
         semP(sem);
         printf("proces o pd =  %d znajduje sie w sekcji krytycznej\n",getpid());
         usleep(rand()%100);
         printf("proces o pid = %d opuszcza semafor\n",getpid());
         semV(sem);
  return 0;
}
   
