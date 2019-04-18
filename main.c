#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char** argv){

  if(argc < 2){
    perror("Usage: <protocol> <IP>");
    exit(1);
  }
  char* protocol = argv[1];
  char* ip = argv[2];

    if(!strcmp("arp", protocol)){
      printf("arp protocol\n");
      // First there should be a broadcast message to see the MAC address of the owner of the IP address. -> broadcast message shoudl be created and sent over socket.
      // After getting the MAC address, show in the console the output just like the output of the real arp x.x.x.x
    }
    if(!strcmp("icmp", protocol)){
      printf("ping\n");
      // First, it should lookup the arp table to find the MAC address. If it exists, then it's OK. If not, the broadcast message should be created to find the MAC address.
      // After that, fill the headers.
  }
  return 0;
}
