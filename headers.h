#ifndef HEADERS_H
#define HEADERS_H
#include <sys/types.h>        // needed for socket(), uint8_t, uint16_t
struct ethernetheader {         //     0 1 2 3 4 5 6 7 8 9 10 11  12  13
  uint8_t source_mac[6];        //     +--------------------------------+
  uint8_t destination_mac[6];   //     |   Dst.   |  Src.       | Type  |
  unsigned char type;           //     |  Address | Address     |       |
};                              //     +--------------------------------+


struct ipheader {                        //  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
 unsigned char      iph_ihl:5, iph_ver:4;// +-------+------+----------------+-------------------------------+
 unsigned char      iph_tos;            //  |Version|  IHL | Type Of Service|        Total Length           |
 unsigned short int iph_len;            //  |-------+-----------------------+-----+-------------------------|
 unsigned short int iph_ident;          //  |       Identification          |Flags|   Fragment Offset       |
 unsigned char      iph_flag;           //  |-------------------------------+-----+-------------------------|
 unsigned short int iph_offset;         //  |  TimeToLive  |    Protocol    |      Header Checksum          |
 unsigned char      iph_ttl;            //  |--------------+----------------+-------------------------------|
 unsigned char      iph_protocol;       //  |                       Source Address                          |
 unsigned short int iph_chksum;         //  |---------------------------------------------------------------|
 uint8_t       iph_sourceip[4];         //  |                    Destination Address                        |
 uint8_t       iph_destip[4];           //  |---------------------------------------------------------------|
};                                      //  |                    Options                    |    Padding    |
                                        //  |-----------------------------------------------+---------------|


                                                                                // 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
struct tcpheader {                                                              // +-------------------------------------------------------------+
 unsigned short int tcph_srcport;                                               // |         Source Port          |       Destination Port       |
 unsigned short int tcph_destport;                                              // +------------------------------+------------------------------+
 unsigned int       tcph_seqnum;                                                // |                    Sequence Number                          |
 unsigned int       tcph_acknum;                                                // +-------------------------------------------------------------+
 unsigned char      tcph_reserved:4, tcph_offset:4;                             // |                     Acknowledge Number                      |
 // unsigned char tcph_flags;                                                   // +-------------------------------------------------------------+
  unsigned int                                                                  // |  Data  |        |N|U|A|P|R|S|F|                             |
       tcp_res1:4,      /*little-endian*/                                       // |  Offset|  Resv. |S|R|C|S|S|Y|I|           Window            |
       tcph_hlen:4,     /*length of tcp header in 32-bit words*/                // |        |        | |G|K|H|T|N|N|                             |
       tcph_fin:1,      /*Finish flag "fin"*/                                   // +--------+--------+-+-+-+-+-+-+-+-----------------------------|
       tcph_syn:1,       /*Synchronize sequence numbers to start a connection*/ // |        Checksum               |       Urgent pointer        |
       tcph_rst:1,      /*Reset flag */                                         // +-------------------------------+-----------------------------|
       tcph_psh:1,      /*Push, sends data to the application*/                 // |         Options                              |    Padding   |
       tcph_ack:1,      /*acknowledge*/                                         // +----------------------------------------------+--------------|
       tcph_urg:1,      /*urgent pointer*/                                      // |                          Data                               |
       tcph_res2:2;                                                             // +-------------------------------------------------------------+
 unsigned short int tcph_win;
 unsigned short int tcph_chksum;
 unsigned short int tcph_urgptr;
};

struct udpheader {                  //+--------------------------------------------+
unsigned short int udph_srcport;    //|      Soruce Port      |    Destination Port |
unsigned short int udph_destport;   //|----------------------+---------------------+
unsigned short int udph_len;        //|       Length         |       Checksum      |
unsigned short int udph_chksum;     //+--------------------------------------------+
};

struct icmpheader {                                           //+-------------------------------------+
 unsigned char      icmph_type;                               //   type     | code    |   Checksum    |
 unsigned char      icmph_code;                               //+-----------+---------+---------------+
 unsigned short int icmph_chksum;                             //|     Identifier      | Seq number    |
 /* The following data structures are ICMP type specific */   //+---------------------+---------------+
 unsigned short int icmph_ident;
 unsigned short int icmph_seqnum;
};/* total ICMP header length: 8 bytes (= 64 bits) */

typedef struct _arp_hdr arp_hdr;
struct _arp_hdr {
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
} //                                                 |                  Dst Proto Address              |
//                                                   +-------------------------------------------------+
#endif
