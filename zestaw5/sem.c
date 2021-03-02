#include <stdio.h>
#include <stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<semaphore.h>
#include"pthread.h"
#include"sem.h"

semid semOpen(const char *name){
  semid try = sem_open(name,O_CREAT,S_IRWXU,0);
  if(try == SEM_FAILED){
      perror("sem_open err\n");
      exit(0);
   } 
   printf("Semafor o nazwie '%s' zostal otwarty\n",name);
 return try;
}

void semInit(semid sem, int val){
  int sval;
  int try = sem_getvalue(sem,&sval);
   if(try==-1){
   perror("sem_getvalue err\n");
   exit(0);
  }
  int dif = val - sval;
  if(dif>0){
       int i;
       for(i=0;i<dif;i++){
          try = sem_post(sem);
            if(try==-1){
              perror("sem_post err\n");
              exit(0);
             }
            }
         }
  if(dif<0){
       int i;
       for(i=0;i<-dif;i++){
          try = sem_wait(sem);
            if(try==-1){
              perror("sem_wait err\n");
              exit(0);
             }
           }
        }
  printf("semafor zostal zainiciowany\n");
}

void semRm(semid sem,const char* name){
 int try =  sem_destroy(sem);
 if(try==-1){
   perror("sem_destroy err\n");
   exit(0);
  }
 try =  sem_unlink(name);
 if(try==-1){
   perror("sem_unlink err\n");
   exit(0);
  }
  printf("Semator zostal zniszczony\n");
}

void semP(semid sem){
 int try = sem_wait(sem);
 if(try==-1){
   perror("sem_wait err\n");
   exit(0);
  }
  printf("semafor zostal opuszczony\n");
}

void semV(semid sem){
 int try = sem_post(sem);
 if(try==-1){
   perror("sem_post err\n");
   exit(0);
  }
 printf("semafor zostal podniesiony\n");
}

void semZ(semid sem){ 
 int sval;
 do{
   sleep(1);
   int try = sem_getvalue(sem,&sval);
   if(try==-1){
   perror("sem_getvalue err\n");
   exit(0);
  }
 printf("oczekiwanie na wyzerowanie\n");
 } while(sval!=0);
}

void semInfo(semid sem){
 int sval;
 int try = sem_getvalue(sem,&sval);
   if(try==-1){
   perror("sem_getvalue err\n");
   exit(0);
  }
 if(sval>=0) printf("sem_value: %d\n", sval);
 if(sval<0) printf("number of postponed processes: %d\n", sval);
}




   

