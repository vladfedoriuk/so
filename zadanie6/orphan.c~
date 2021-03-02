#include<stdio.h>
#include"procinfo.h"
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
    switch(fork()){
       case -1:
         perror("fork error");
         exit(EXIT_FAILURE);
         break;
       case 0:
          procinfo(argv[0]);
          sleep(4);
          break;
       default: 
          break;
     }
  return 0;
}
