#include <SPI.h>                      
#include "RF24.h"                     
void conditionW();
int msg[1];

RF24 radio(9,10);                     
                                      
const uint64_t pipe = 0xE8E8F0F0E1LL; 

bool forward;
bool backward;

String condition="";

void setup(void){
  radio.begin();                      
  radio.openWritingPipe(pipe); 
  Serial.begin(9600);

}

void loop(void){
  if(Serial.available() >0){
     condition = Serial.readString();
     conditionW();
  }

  Serial.println(msg[0]);
  radio.write(msg, 1);
}
