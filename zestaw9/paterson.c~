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

#define NUM_OF_THREADS 2

volatile bool flaga[NUM_OF_THREADS];
volatile int kolej;

typedef struct{
   int index;
   char name[16];
 }data;

volatile int count;



void lock(data* inf){

  __sync_synchronize();
   //asm volatile ("" : : : "memory");
   //asm volatile ("mfence" ::: "memory");
   
   flaga[inf->index]=true;
   kolej = 1 - inf->index;

   __sync_synchronize();
  // asm volatile ("" : : : "memory");
  // asm volatile ("mfence" ::: "memory");
   while(flaga[1-inf->index] && kolej == 1 - inf->index);

 }


void unlock(data* inf){

 flaga[inf->index] = false;
 
}


void* thread(void* arg);

void* thread(void *arg){
 int i;
 data* inf = (data*)arg;
 for(i=0;i<100000000;i++){
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
   flaga[i] = false;
 }
 kolej = 0;

 data info[NUM_OF_THREADS];

 info[0].index = 0;
 strcpy(info[0].name,"First one");
 info[1].index = 1;
 strcpy(info[1].name,"Second one");

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
 printf("size of void*: %d\n", sizeof(void*));
 printf("size of int: %d\n", sizeof(int));
 return 0;
}
