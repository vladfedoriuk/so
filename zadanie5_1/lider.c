#include<stdio.h>
#include"procinfo.h"
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
  procinfo(argv[0]);
  int i;
  for(i=0;i<3;i++){
    switch(fork()){
       case -1:
         perror("fork error");
         exit(EXIT_FAILURE);
         break;
       case 0:
          setpgid(getpid(),0);
          procinfo(argv[0]);
          sleep(1);
          break;
       default: 
           wait(NULL);
          break;
     }
  }
  return 0;
}
