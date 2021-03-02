#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
#include"procinfo.h"
#include<stdlib.h>

void shandler(int);
void shandler(int syg){
  printf("Otrymano sygnal z numerem %d\n",syg);	
	sleep(3);
}

int main(int argc, char* argv[]){
 procinfo(argv[0]);
 int syg=-1;
 char arg1;
 if(argc<=2){
   perror("Nieprawidlowe urochomiene\n");
   exit(EXIT_FAILURE);
  } 
  if(argc==3){
       syg = atoi(argv[2]);
      }
     arg1= argv[1][0];
     switch(arg1){
        case 'd':
           if(signal(syg,SIG_DFL)==SIG_ERR){
              perror("Blad domyslnej obslugi\n");
              exit(EXIT_FAILURE);
             }
           break;
        case 'i':
           if(signal(syg,SIG_IGN)==SIG_ERR){
              perror("Blad SIG_ING\n");
              exit(EXIT_FAILURE);
            }
           break;
        case 'p':
            if(signal(syg,shandler)==SIG_ERR){
              perror("Blad obslugi syg_handlera\n");
              exit(EXIT_FAILURE);
             }
           break; 
         default:
                perror("Nieprawidlowy argument operacji\n");
                exit(EXIT_FAILURE);
                break;
   }
 sleep(100);
 sleep(4);
 return 0;
}
