#include "Arduino.h"
#include "Shift_register.h"




/*  No operation:
 *  If the arduino is to fast for the shift register,
 *  it could help to activate the NOP.
 *  To do this, remove the "//" infront of "__asm__("nop\n\t")"
 */
#define NOP //__asm__("nop\n\t")




//Setup the objekt
SR::SR(int DS, int SHCP, int STCP){
  pinMode(DS, OUTPUT);
  pinMode(SHCP, OUTPUT);
  pinMode(STCP, OUTPUT);
  this->_DS = DS;
  this->_SHCP = SHCP;
  this->_STCP = STCP;
}




//to shift a singel Item in the register

void SR::itemIn(bool item){
  digitalWrite(_DS, item);
  digitalWrite(_SHCP, HIGH);
  NOP;
  digitalWrite(_SHCP, LOW);
  digitalWrite(_STCP, HIGH);
  NOP;
  digitalWrite(_STCP, LOW);
}




//shift 30 times a 0 in the register to clear it

void SR::clear(){
  for(int i=0; i<30; i++){
    digitalWrite(_DS, LOW);
    digitalWrite(_SHCP, HIGH);
    NOP;
    digitalWrite(_SHCP, LOW);
  }
  digitalWrite(_STCP, HIGH);
  NOP;
  digitalWrite(_STCP, LOW);
}




//!!!!!!!!!!at "*muster" you have to send an pointer on the first element of an Array!!!!!!!!!!!

//to shift a Muster in the register

void SR::musterIn(bool *muster, int length){
  for(int i=0; i<length; i++){
    //set datapin
    digitalWrite(_DS, muster[i]);

    //shift in register memory
    digitalWrite(_SHCP, HIGH);
    NOP;
    digitalWrite(_SHCP, LOW);
  }

  //set to output
  digitalWrite(_STCP, HIGH);
  NOP;
  digitalWrite(_STCP, LOW);
}




//to shift a Muster in the register whith an delay after each Item

void SR::musterIn(bool *muster, int length, int wait){
  for(int i=0; i<length; i++){
    //set datapin
    digitalWrite(_DS, muster[i]);

    //shift in register memory
    digitalWrite(_SHCP, HIGH);
    NOP;
    digitalWrite(_SHCP, LOW);

    //set to output
    digitalWrite(_STCP, HIGH);
    NOP;
    digitalWrite(_STCP, LOW);

    //wait
    delay(wait);
  }
}




//to shift a Muster in the register whith an delay bevor each Item

void SR::musterIn(int wait, bool *muster, int length){
  for(int i=0; i<length; i++){
    //wait
    delay(wait);

    //set datapin
    digitalWrite(_DS, muster[i]);

    //shift in register memory
    digitalWrite(_SHCP, HIGH);
    NOP;
    digitalWrite(_SHCP, LOW);

    //set to output
    digitalWrite(_STCP, HIGH);
    NOP;
    digitalWrite(_STCP, LOW);
  }
}




//Not ready at the moment
/*
void SR::musterIn2(bool muster[]){

  for(int i=0; i<sizeof(muster); i++){
    digitalWrite(_DS, muster[i]);
    digitalWrite(_SHCP, HIGH);
    NOP;
    digitalWrite(_SHCP, LOW);
  }
  digitalWrite(_STCP, HIGH);
  NOP;
  digitalWrite(_STCP, LOW);
}*/




//returns th value off DS
void SR::getDS(){
  return _DS;
}




//returns th value off SHCP
void SR::getSHCP(){
  return _SHCP;
}




//returns th value off STCP
void SR::getSTCP(){
  return _STCP;
}




//Print the first and two times the third item out off an array on the Serial monitor 
void SR::printmuster(bool *pointer){
  Serial.println(*pointer);
  Serial.println(*(pointer+2));
  bool *x = pointer+2;
  Serial.println(*x);
}



