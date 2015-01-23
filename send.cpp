/*
 Usage: ./send <TriStateCode>
*/

#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int PIN = 0;

  if(wiringPiSetup () == -1)  {
    printf("Setting up WiringPi failed.\n");
    return -1;
  }

  if(argc < 2) {
    printf("Usage: ./send <TriStateCode>");
    return -1;
  }

  char* code = argv[1];
  int length = strlen(code);
  for(int i = 0; i < length; i++) {
    if(code[i] != '0' && code[i] != '1' && code[i] != 'F') {
      printf("Argument is not a TriState code: %s\n", code);
      return -1;
    }
  }
  RCSwitch mySwitch = RCSwitch();
  mySwitch.enableTransmit(PIN);

  printf("Sending code: %s\n", code);
  mySwitch.sendTriState(code);  
  return 0;
}
