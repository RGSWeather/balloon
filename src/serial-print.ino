/* Header file that allows for writing of data from arduino to pi */


#ifndef serial-print_h
#define serial-print_h

#include "Arduino.h"

import processing.serial.*;
Serial mySerial;
PrintWriter output;
void setup() {
   mySerial = new Serial( this, Serial.list()[0], 9600 );
   output = createWriter( "data.txt" );
}
void draw() {
    if (mySerial.available() > 0 ) {
         String value = mySerial.readString();
         if ( value != null ) {
              output.println( value );
         }
    }
}

void keyPressed() {
    output.flush();  // Writes the remaining data to the file
    output.close();  // Finishes the file
    exit();  // Stops the program
}

#endif
