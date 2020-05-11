/* To use this, you need two circles out of 12 LEDs(on is in the other), every one is conected to two shift registers, which are
 * connected in series.
 * 
 * Then the circles will simulate a "Klick_klack_ball"
 * 
 * Created by Florian Etzel
 * 11.05.2020
 */

#include <Shift_register.h>

//create shortcut for the delay
#define del delay(wait);

//Datapins
int DS1=10;
int DS2=13;

//Shiftpins
int SHCP1=8;
int SHCP2=11;

//Setpins
int STCPin1=9;
int STCPin2=12;

//creat the delay time
int wait = 50;

//Create the shift registers
SR sr1(DS1, SHCP1, STCPin1);
SR sr2(DS2, SHCP2, STCPin2);

//create the musters
bool muster1[] = {1,1,0,0,0,0,0,0,0,0,0,1};
bool muster2[] = {1,1,0,0,0,0,0,0,0,0,0,1};

void setup() {
  //start serial comunication to PC
  Serial.begin(9600);

  //Clear the shift registers
  sr1.clear();
  sr2.clear();

  //Printing on Serial Monitor
  Serial.println("Set up done");
  Serial.println("LED cleared");
}

void loop() {

  //shift the muster in the register
  //"&muster[0]" is a pointer to the first array element
  //"sizeof(muster1)" ist die länge des arrays
  //"wait" is the delay time after each item
  sr1.musterIn(&muster1[0], sizeof(muster1), wait);
  sr2.musterIn(&muster2[0], sizeof(muster2), wait);

  //Printing on Serial Monitor
  Serial.println("Muster written");
}
