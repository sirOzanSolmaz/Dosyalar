#include <SPI.h>      
#include "RF24.h"             
void forward();
void backward();
void stopFunc();

RF24 radio(9,10);    
  
const uint64_t pipe = 0xE8E8F0F0E1LL; 

int msg[1]; 

void setup(){
  Serial.begin(9600);            
  radio.begin();                    
  radio.openReadingPipe(1, pipe);   
  radio.startListening();
  for(int i = 2; i<6; i++){
    pinMode(i,OUTPUT);
  }
}

void loop(){
  
  if(radio.available()){            
    bool done = false;               
    
    while (!done) {
      done = radio.read(msg, 1);
      Serial.println(msg[0]);
      if(msg[0] == 1){
        forward();
      }else if(msg[0] == 2){
        backward();
      }else if(msg[0] == 3){
        stopFunc();
      }
   }
  }
}
