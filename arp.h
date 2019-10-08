#ifndef ARP_H
#define ARP_H
#include <stdint.h>

struct _arp_hdr;
typedef struct _arp_hdr arp_hdr;
/*struct _arp_hdr {
  uint8_t target_ip[4];   //                         +-------------------------------------------------+
  uint8_t sender_ip[4]; //                           |        HW type           |     Protocol Type    |
  uint16_t htype;  //Hardware type                   +-------------------------------------------------+
  uint16_t ptype;  //Protocol type                   | HW Length | Proto Length |        Opcode        |
  uint8_t hlen;    //Hardware address length         +-------------------------------------------------+
  uint8_t plen;    //Protocol address length         |                       Src Mac                   |
  uint16_t opcode;                                 //+-------------------------------------------------+
  uint8_t source_mac[6];                           //|                  Src Proto Address              |
  uint8_t destination_mac[6];                      //+-------------------------------------------------+
                                                   //|                  Dst Mac (0xFFFFFF)             |
                                                   //+-------------------------------------------------+
};*/ //                                                |                  Dst Proto Address              |
//                                                   +-------------------------------------------------+
// Function prototypes
char* allocate_strmem (int);
u_int8_t* allocate_ustrmem (int);
int arp_request();
int arp_reply();


#endif
