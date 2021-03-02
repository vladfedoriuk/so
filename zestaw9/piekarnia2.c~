#define _REENTRANT

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include"pthread.h"
#include<sys/types.h>
#include<stdbool.h>

#define NUM_OF_THREADS 4

volatile bool wybieranie[NUM_OF_THREADS];
volatile int numer[NUM_OF_THREADS];

typedef struct{
   int index;
   char name[16];
 }data;

volatile int count;

int max(){
 int mx = numer[0];
 int i;
 for(i=1;i<NUM_OF_THREADS;i++)
   if(mx<numer[i]) mx = numer[i];
 return mx;
}


void lock(data* inf){
   //asm volatile ("mfence" ::: "memory");
  __sync_synchronize();

   
   wybieranie[inf->index] = true;
  
  
  // asm volatile ("mfence" ::: "memory");
  __sync_synchronize();

   
   numer[inf->index] = max()+1;

  
  // asm volatile ("mfence" ::: "memory");
  __sync_synchronize();

   
   wybieranie[inf->index] = false;
   

   int j;
   //asm volatile ("mfence" ::: "memory");
   __sync_synchronize();
   for(j= 0; j< NUM_OF_THREADS; j++){
    while(wybieranie[j]);
    while(numer[j]!=0 && (numer[j]<numer[inf->index] || (numer[j]==numer[inf->index] && j<inf->index)));
 }
}

void unlock(data* inf){

 numer[inf->index] = 0;
 
}


void* thread(void* arg);

void* thread(void *arg){
 int i;
 data* inf = (data*)arg;
 for(i=0;i<10000000;i++){
   lock(inf);
   count++;
   unlock(inf);
 }
 pthread_exit(NULL);
}

int main(int argc, char *argv[]){
 printf("\033c");
 int try;

 int i;

 for(i=0;i<NUM_OF_THREADS;i++){
   numer[i] = 0;
   wybieranie[i] = false;
 }

 data info[NUM_OF_THREADS];

 info[0].index = 0;
 strcpy(info[0].name,"First one");
 info[1].index = 1;
 strcpy(info[1].name,"Second one");
 info[2].index = 2;
 strcpy(info[2].name,"Third one");
 info[3].index = 3;
 strcpy(info[3].name,"Forth one");

 pthread_t tid[NUM_OF_THREADS];

 for(i=0;i<NUM_OF_THREADS;i++){
   int try = pthread_create(&tid[i],NULL,thread,(void*)(&info[i]));
   if(try !=0){
     perror("pthread_create failed");
     exit(EXIT_FAILURE);
   }
 }
 for(i=0;i<NUM_OF_THREADS;i++){
   int try = pthread_join(tid[i],NULL);
   if(try!=0){
      perror("pthread_join failed");
      exit(EXIT_FAILURE);
   }
 }
 printf("Number of threads that visited critical section: %d\n",count); 
 
 return 0;
}

