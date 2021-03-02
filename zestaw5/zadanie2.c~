#include <stdio.h>
#include <stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<semaphore.h>
#include"pthread.h"
#include"sem.h"
#include<string.h>

semid sem;

int main(int argc, char* argv[]){
 sem = semOpen("sem");
 char c;
 scanf("%c",&c);
 while(1){
 switch(c){
    case 'i':
       semInit(sem,3);
       semInfo(sem);
       break;
   case 'r':
       semRm(sem,"sem");
       break;
   case 'p':
       semP(sem);
       break;
   case 'v':
       semV(sem);
       break;
   case 'z':
       semZ(sem);
       semP(sem);
       semInfo(sem);
       break;
   case 'q':
       semInfo(sem);
       break;
  }
 scanf("%c",&c);
 }
 return 0;
}
       
