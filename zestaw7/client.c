#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<stdlib.h>
#include"pthread.h"
#include"msg.h"
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc, char* argv[]){
  MESSAGE msg;
  scanf("%.*s", BUFSIZE, msg.buffer);
  int id=1;
  int msg_q_id = msgCreate(id);
  msg.msg_to=SERVER;
  msg.msg_from=(long)getpid();
  msgSend(msg_q_id,&msg);
  msgRecv(msg_q_id,&msg,(long)getpid());
  printf("%s\n",msg.buffer);
  return 0;
}
