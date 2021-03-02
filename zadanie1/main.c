#include<stdio.h>
#include"procinfo.h"
#include<unistd.h>

int main(int argc, char* argv[]){
 procinfo(argv[0]); //argv[0] - nazwa wywolanego programu
 return 0;
}
