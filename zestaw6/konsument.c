#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<semaphore.h>
#include"pthread.h"
#include"sem.h"
#include<string.h>
#include"shm.h"
#include<sys/mman.h> 
#include<sys/types.h>

#define N 30

semid sem_prod,sem_kons;

int main(int argc, char* argv[]){
       sem_prod = semOpen("sem_prod");
       sem_kons = semOpen("sem_kons");
       int fd = shmOpen("shm");
       cykliczny* ptr =shmMap(fd,sizeof(cykliczny));
       int i;
       FILE* f;
           if((f=fopen("output.txt","w"))==NULL){
             perror("Nie udalo sie otworzyc plik do zapisywania");
             exit(EXIT_FAILURE);
           }
       
       for(i=0;i<N;i++){
         semP(sem_kons);
         int d = ptr->buf[ptr->beg];
         fprintf(f,"%d ",d);
         printf("Otrzymano %d\n",d);
         ptr->beg=(ptr->beg+1)&(SIZE-1);
         semV(sem_prod);
       }
  fclose(f);
  return 0;
}
