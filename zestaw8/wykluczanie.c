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

#define NUM_OF_THREADS 5

typedef struct{
   int index;
   char name[16];
 }data;

int count;

pthread_mutex_t my_mutex;

void* thread(void* arg);

void* thread(void *arg){
 sleep(1);
 int local;
 int i,try;
 static int x = 0;
 data* inf = (data*)arg;
 for(i=0;i<20;i++){
   printf("\033[1m\033[33m\033[%d;%dH %s (%d) waits\n",inf->index+1,0,inf->name,inf->index+1);
   try = pthread_mutex_lock(&my_mutex);
   if(try!=0){
    perror("pthread_mutex_lock failed");
    exit(EXIT_FAILURE);
   }
   local = count;
   local++;
   usleep(100000);
   count = local;
   printf("\033[1m\033[35m\033[%d;%dH %s (%d) in critical section\n",inf->index+1,40,inf->name,inf->index+1);
   printf("\033c");
   try = pthread_mutex_unlock(&my_mutex);
   if(try!=0){
    perror("pthread_mutex_unlock failed");
    exit(EXIT_FAILURE);
   }
   usleep(100000);
 }
 x++;
 pthread_exit(NULL);
}

int main(int argc, char *argv[]){
 printf("\033c");
 int try;
 try = pthread_mutex_init(&my_mutex,NULL);
 if(try!=0){
  perror("pthread_mutex_init failed");
  exit(EXIT_FAILURE);
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
 info[4].index = 4;
 strcpy(info[4].name,"Fifth one");

 pthread_t tid[NUM_OF_THREADS];

 int i;
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
 try = pthread_mutex_destroy(&my_mutex);
 if(try!=0){
   perror("pthread_mutex_destroy failed");
   exit(EXIT_FAILURE);
 }
 
 return 0;
}

