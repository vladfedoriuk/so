#include<stdio.h>
#include<fcntl.h>

int main(int argc, char* argv[]){

   int fd1,fd2,n;
   char buf[4096];
     if(argc!=3){
             perror("Nieprawidlowa liczba argumentow");
             return -1;
     }
     if((fd1=open(argv[1],O_RDONLY,0))==-1){
             perror("Nie udalo sie otworzyc pliku do czytania");
             return -2;
     }
     if((fd2=open(argv[2],O_WRONLY,0))==-1){
             perror("Nie udalo sie otworzyc pliku do wypisywania");
             return -3;
     }
     while((n=read(fd1,buf,sizeof(buf)))>0)
       if(write(fd2,buf,n)!=n){
             perror("Pomylka zapisywania do pliku");
             return -4;
           }
     return 0;
}
