#include<stdio.h>
#include"procinfo.h"

void procinfo(char *nazwa){
  printf("Identyfikatory oraz nazwa programu:\tUID:\t%d\tGID:\t%d\tPID:\t%d\tPPID:\t%d\tPGID:\t%d\t%s\n",getuid(),getgid(),getpid(),getppid(),getpgid(getpid()),nazwa);
} 
