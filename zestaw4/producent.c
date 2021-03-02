#include<sys/types.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<limits.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
 FILE* f1;
 if((f1=fopen("magazyn.txt","r"))==NULL){
             perror("Nie udalo sie otworzyc plik do czytania");
             exit(EXIT_FAILURE);
          }
printf("Otworzono magazyn.txt \n");
 int fd;
 if((fd=open(argv[1],O_WRONLY))==-1){
             perror("Nie udalo sie otworzyc potok do zapisywania");
             exit(EXIT_FAILURE);
          }
printf("Otworzono potok do zapisywania\n");
int nw=0;  
printf("Zapisuje\n");
char buf[PIPE_BUF];
        while(!feof(f1)){
           if(fgets(buf,sizeof(buf),f1)){
             printf("%s\n",buf);
             nw=write(fd,buf,sizeof(buf));
             if(nw==-1){
               perror("Write error");
               exit(EXIT_FAILURE);
            }
         }
      }
      printf("end of writing to pipe\n");
      fclose(f1);
  return 0;
}
