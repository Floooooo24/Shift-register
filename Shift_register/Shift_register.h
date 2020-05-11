/*  A library, which will handel the data transfer
 *  with a shift register for you
 *
 *  Created by Florian Etzel
 *  27.03.2020
 */

#ifndef Shift_register_h
#define Shift_register_h

#include "Arduino.h"

class SR {
  public:
    //constructor:
    SR(int DS, int SHCP, int STCP);

    //normal Funktions
    void itemIn(bool item);   //to shift a singel Item in the register
    void clear();      //shift 30 times a 0 in the register to clear it

//!!!!!!!!!!at "*muster" you have to send an pointer on the first element of an Array!!!!!!!!!!!
    void musterIn(bool *muster, int length);    //to shift a Muster in the register
    void musterIn(bool *muster, int length, int wait);    //to shift a Muster in the register whith an delay after each Item
    void musterIn(int wait, bool *muster, int length);    //to shift a Muster in the register whith an delay bevor each Item

    //Not ready at the moment
    //void musterIn2(bool muster[]);

    //debugger Funktions
    void getDS();       //returns th value off DS
    void getSHCP();     //returns th value off SHCP
    void getSTCP();     //returns th value off STCP
    void printmuster(bool *pointer);    //Print the first and two times the third item out off an array on the Serial monitor 

  private:
    
    //conection Pins:
    int _DS;
    int _SHCP;
    int _STCP;
};

#endif
