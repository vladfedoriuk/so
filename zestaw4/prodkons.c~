#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<limits.h>
#include<string.h>

void proces_macierzysty(char buf[], int filedes[], int nw){
FILE* f1;
close(filedes[0]);
if((f1=fopen("magazyn.txt","r"))==NULL){
             perror("Nie udalo sie otworzyc plik do czytania");
             exit(EXIT_FAILURE);
          }
        while(!feof(f1)){
           if(fgets(buf,sizeof(buf),f1)){
             nw=write(filedes[1],buf,sizeof(buf));
             printf("%s\n",buf);
             if(nw==-1){
               perror("Write error");
               exit(EXIT_FAILURE);
            }
         }
      }
      printf("end of write to pipe\n");
      close(filedes[1]);
      fclose(f1);
}

void proces_potomny(char buf[], int filedes[], int nr){
           FILE* f2;
           close(filedes[1]);
           if((f2=fopen("schowek.txt","w"))==NULL){
             perror("Nie udalo sie otworzyc plik do zapisywania");
             exit(EXIT_FAILURE);
           }
        while((nr=read(filedes[0],buf,sizeof(buf)))!=0){
          if(nr==-1){
            perror("Read error");
            exit(EXIT_FAILURE);
          }
         fputs(buf,f2);
         printf("%s\n",buf);
         usleep(rand()%100);
        }
        printf("end of read from pipe\n");
        close(filedes[0]);
        fclose(f2);
}
int main(int argc, char* argv[0]){ 
 int set = time(NULL);
 srand(set);
 int filedes[2];
 if(pipe(filedes)==-1){
   perror("Nie udalo sie stworzyc potok");
   exit(EXIT_FAILURE);
 }
 int nw=0,nr=0;
 char buf[PIPE_BUF];
  switch(fork()){
    case -1:
        perror("Fork error");
        exit(EXIT_FAILURE);
        break;
    case 0: 
        proces_potomny(buf,filedes,nr);
        break;
   default: 
       proces_macierzysty(buf,filedes,nw);  
       wait(NULL);
       break;
  }
 return 0;
}

        
         
