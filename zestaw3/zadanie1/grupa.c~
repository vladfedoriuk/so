#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h> 
#include"procinfo.h"

void shandler(int syg){
  printf("Otrymano sygnal z numerem %d\n",syg);
  exit(0);
}

void proc( int syg, char *name ){
  switch ( fork () )
	{
	  case -1:
	   perror ("Fork error");
	   exit (EXIT_FAILURE);
	   break;
	  case 0:
             procinfo(name);
	     if(signal(syg,shandler)==SIG_ERR){
              perror("Blad obslugi syg_handlera\n");
              exit(EXIT_FAILURE);
             }  
           sleep(6);
	   break;
          default:
            sleep(1);
            break;
	}
 }
int main(int argc, char *argv[]){
       printf("1 procinfo\n");
       procinfo(argv[0]);
       pid_t p = getpid();
       if (argc != 2){
	perror ("Nieprawidlowa liczba argumentow.");
	exit (EXIT_FAILURE);
	}
       int syg = atoi(argv[1]); 
       printf("2 procinfo\n");     	
       proc(syg,argv[0]);
       if(p==getpid()){
       printf("3 procinfo\n");
       proc(syg,argv[0]);
       }
       if(p==getpid()){
       printf("4 procinfo\n");
       proc(syg,argv[0]);
       }
       if(p==getpid()){
         if(signal(syg,SIG_DFL)==SIG_ERR){
              perror("Blad obslugi syg_handlera\n");
              exit(EXIT_FAILURE);
             } 
        kill (-getpgid(p), syg);
	}
       if(p==getpid()){
          int i;
           for(i=0;i<3;i++){
            wait(NULL);
           }
         } 
	return 0;
}

