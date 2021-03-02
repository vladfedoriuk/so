#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<stdlib.h>
#include"pthread.h"
#include"msg.h"
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc, char* argv[]){
  MESSAGE msg;
  int id=1;
  int msg_q_id = msgCreate(id);
  msgInfo(msg_q_id);
  int i;
  for(i = 0; i < 5; i++){
    msgRecv(msg_q_id,&msg,SERVER);
    msgInfo(msg_q_id);
    long temp = msg.msg_to;
    msg.msg_to = msg.msg_from;
    msg.msg_from = temp;
    int j=0;
    while(msg.buffer[j]!='\0'){
          msg.buffer[j] = toupper(msg.buffer[j]);
          j++;
    }
    msgSend(msg_q_id,&msg);
 }
 msgRm(msg_q_id);
 return 0;
}
    
