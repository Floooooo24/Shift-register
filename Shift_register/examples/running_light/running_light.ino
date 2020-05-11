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

  //shift a "1" in
  sr1.itemIn(1);

  //wait
  del

  //shift 8 times a zero in and wait after each
  for(int i=0; i<7; i++){
    sr1.itemIn(0);
    del
  }

  //Printing on Serial Monitor
  Serial.println("Muster written");
}
