//
// IP_Manipulator.cpp
// ~~~~~~~~~~~~~~~~~~~~~~~
//
// Input: decimal, hex, octal, or dotted notations
//
// 

#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
  struct in_addr cp; //dotted-decimal notation

  if (argc != 2) {
    fprintf(stderr,"Usage: IP_Manipulator <dotted-quad>\n");
    exit(1);
  }

  inet_aton(argv[1],&cp);

  // ntohl: convert from network byte order to host byte order
  unsigned int address = ntohl(cp.s_addr);

  unsigned int octetA = (0xff000000 & address)>>24;
  unsigned int octetB = (0x00ff0000 & address)>>16;
  unsigned int octetC = (0x0000ff00 & address)>>8;
  unsigned int octetD = 0x000000ff & address;

  printf("IP Manipulator\n");
  printf("--------------\n");

  printf("%s --> %u.%u.%u.%u  :: (Decimal)\n",argv[1],octetA,octetB,octetC,octetD);
  printf("%s --> %u.%u.%u  :: (Decimal)\n",argv[1],octetA,octetB,(octetC<<8) + octetD);
  printf("%s --> %u.%u  :: (Decimal)\n",argv[1],octetA,(octetB<<16) + (octetC<<8) + octetD);
  printf("%s --> %u  :: (Decimal)\n",argv[1],address);

  printf("%s --> %#x.%#x.%#x.%#x  :: (Hex)\n",argv[1],octetA,octetB,octetC,octetD);
  printf("%s --> %#x.%#x.%#x  :: (Hex)\n",argv[1],octetA,octetB,(octetC<<8) + octetD);
  printf("%s --> %#x.%#x  :: (Hex)\n",argv[1],octetA,(octetB<<16) + (octetC<<8) + octetD);
  printf("%s --> %#x  :: (Hex)\n",argv[1],address);

  printf("%s --> %#o.%#o.%#o.%#o  :: (Octal)\n",argv[1],octetA,octetB,octetC,octetD);
  printf("%s --> %#o.%#o.%#o  :: (Octal)\n",argv[1],octetA,octetB,(octetC<<8) + octetD);
  printf("%s --> %#o.%#o  :: (Octal)\n",argv[1],octetA,(octetB<<16) + (octetC<<8) + octetD);
  printf("%s --> %#o  :: (Octal)\n",argv[1],address);

}