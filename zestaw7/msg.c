#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include"pthread.h"
#include"msg.h"
#include<unistd.h>
#include<fcntl.h>

struct msqid_ds buf;

int msgCreate(int id){
  key_t key = ftok("./server.x", id);
  int try = msgget(key,IPC_CREAT|O_RDWR|0666);
  if(try==-1){
     perror("msgget err\n");
     exit(0);
  } 
      return try;
}

void msgRm(int msgid){
 struct msqid_ds *buf;
 int try = msgctl(msgid,IPC_RMID,buf);
 if(try==-1){
    perror("msgctl ipc_rmid err\n");
    exit(0);
  } 
}

void msgSend(int msgid, MESSAGE *msg){
 size_t msgsz = sizeof(MESSAGE) - sizeof(long);
 int try = msgsnd(msgid,msg,msgsz,0);
 if(try == -1){
    perror("msgsnd err\n");
    exit(0);
   }
}

void msgRecv(int msgid, MESSAGE *msg, int mtype){
 size_t msgsz = sizeof(MESSAGE) - sizeof(long);
 int try = msgrcv(msgid,msg,msgsz,mtype,0);
 if(try < 0){
    perror("msgrcv err\n");
    exit(0);
 }
}

void msgInfo(int msgid){

 int try = msgctl(msgid,IPC_STAT,&buf);
 if(try==-1){
    perror("msgctl ipc_stat err\n");
    exit(0);
  } 
  printf("\n");
  printf("Curent number of bytes on queue: %d\n",buf.__msg_cbytes);
  printf("Curent number of messages on queue: %d\n",buf.msg_qnum);
  printf("\n");
}





