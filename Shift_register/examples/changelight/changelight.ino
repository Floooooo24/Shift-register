/*
 * To use this, you need 8 LEDs, which are conected to an shift register.
 * 
 * this code let every 2 LED light, than if will wait 500ms and will light the other ones.
 * 
 * creaded by Florian Etzel
 * 11.05.2020
 */

//include Library
#include <Shift_register.h>

//create shortcut for the delay
#define del delay(wait);

//Datapins
int DS1=10;

//Shiftpins
int SHCP1=8;

//Setpins
int STCPin1=9;

//creat the delay time
int wait = 500;

//Create the shift registers
SR sr1(DS1, SHCP1, STCPin1);

//create the musters
bool muster1[] = {1,0,1,0,1,0,1,0};
bool muster2[] = {0,1,0,1,0,1,0,1};

void setup() {
  //start serial comunication to PC
  Serial.begin(9600);

  //Clear the shift registers
  sr1.clear();

  //Printing on Serial Monitor
  Serial.println("Set up done");
  Serial.println("LED cleared");
}

void loop() {

  sr1.musterIn(&muster1[0], sizeof(muster1));
  del
  sr1.musterIn(&muster2[0], sizeof(muster2));
  del

  //Printing on Serial Monitor
  Serial.println("Muster written");
}
