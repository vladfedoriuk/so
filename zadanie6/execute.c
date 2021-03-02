#include<stdio.h>
#include<unistd.h>
#include"procinfo.h"
#include<stdlib.h>

int main(int argc, char* argv[]){
    printf("komunikat\n");
    char* arg="potomny.x";
    execl("./potomny.x",arg,NULL);
    printf("drugi komunikat\n");
  return 0;
}
