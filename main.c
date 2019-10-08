#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include "arp.h"

int main(int argc, char** argv){

  if(argc < 2){
    perror("Usage: <protocol> [IP]");
    exit(1);
  }
  char* protocol = argv[1];
  //char* ip = argv[2];
  //pthread_t send, receive;
  size_t pid;
    if(!strcmp("arp", protocol)){
      //pthread_create(&send, NULL, arp_request, NULL);
      //pthread_join(receive, NULL);
      pid = fork();
      if(pid == 0)
        arp_request();
      else
        arp_reply();
    }
  return 0;
}
