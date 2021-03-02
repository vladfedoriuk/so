#include<stdio.h>
#include"procinfo.h"
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
  procinfo(argv[0]);
  int i,children=0,k;
  for(i=0;i<3;i++){
    switch(fork()){
       case -1:
         perror("fork error");
         exit(EXIT_FAILURE);
         break;
       case 0:
          procinfo(argv[0]);
          children=0;
          sleep(4);
          break;
       default:
         children++;
          break;
     }
  }
 for(k=0;k<=children+1;k++)
           wait();
  return 0;
}
