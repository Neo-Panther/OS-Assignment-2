#ifndef UTILITIES_H
#define UTILITIES_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <stdint.h>

// shared memory buffer size
#define SHM_BUF_SIZE 901*sizeof(int)

// named semaphores' names
#define WRITE_SEMAPHORE "/write"
#define READ_SEMAPHORE "/read"
#define SYNC_SHM_SEMAPHORE "/syncshm"
#define SEQ_NUM_SEMAPHORE "/sequence"
// process sync shm key
#define SYNC_SHM_KEY 1025
#define SYNC_SHM_SIZE 2*sizeof(int)
#define SHM_READ_COUNT 0
#define SHM_SEQUENCE_NUMBER 1

// ipc permissions
#define PERMS 0600
// msg structure for communication
struct msgbuf {
  long mtype;
  char mtext[1000];
};

// returns the single msgq key
key_t getMsgQKey(){
  key_t key;
  if ((key = ftok("load_balancer.c", 'A')) == -1){
    perror("ftok");
    exit(EXIT_FAILURE);
  }
  return key;
}

// Utility function used to parse input from client
// get index of next space
int get_next_space(char *s, int start){
  int i = start;
  while(s[i]!=' '){
    i++;
  }
  return i+1;
}

#define LOAD_BALANCER 1023
#define SECONDARY_SERVER_2 1022
#define SECONDARY_SERVER_1 1021
#define PRIMARY_SERVER 1020
#endif