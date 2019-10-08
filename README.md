ARP:

First program is for sending and receiving arp messages. There are two functions:

1- arp_request():
  Build up an ARP request message.
  Open up a RAW socket and send the message through the socket via broadcast address.
  TODO:
    a) Implement a function to find which physical link the messages should go through
    b) Implement a function to find source IP address.

2- arp_reply():
Listen for incoming ethernet frame. I expect an ARP ethernet frame of the form:
   MAC (6 bytes) + MAC (6 bytes) + ethernet type (2 bytes) + ethernet data (ARP header) (28 bytes)

TODO:
1) Make interface name as input variable for arp functions.
2) Write a function to fetch ip address of the interface.
3) Clean the code.
4) Complete the documentation.
