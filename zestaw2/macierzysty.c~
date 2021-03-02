#include<stdio.h>
#include"procinfo.h"
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
  procinfo(argv[0]);
  int i,k;
  int children=0;
  char *arg[]={"potomny.x",(char*)NULL};
  for(i=0;i<3;i++){
    switch(fork()){
       case -1:
         perror("fork error");
         exit(EXIT_FAILURE);
         break;
       case 0:
          execv("potomny.x",arg);
          children++;
          break;
       default: 
          break;
     }
}
  for(k=0;k<=children;k++)
          wait(NULL);
  return 0;
}
