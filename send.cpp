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
    printf("Usage: ./send <TriStateCode> [<ON/OFF>]");
    return -1;
  }

  int length = strlen(argv[1]);
  char code[length+4];
  int i = 0;
  for(; i < length; i++) {
    code[i] = argv[1][i];
    if(code[i] != '0' && code[i] != '1' && code[i] != 'F') {
      printf("Argument is not a TriState code: %s\n", code);
      return -1;
    }
  }
  code[i++] = '0';
  code[i++] = 'F';
  code[i++] = 'F';

  if(strcmp(argv[2],"ON") == 0 || strcmp(argv[2],"100") == 0)
    code[i++] = 'F';
  else
    code[i++] = '0';
  RCSwitch mySwitch = RCSwitch();
  mySwitch.enableTransmit(PIN);

  printf("Sending code: %s\n", code);
  mySwitch.sendTriState(code);
  return 0;
}
