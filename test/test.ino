/* Code to test that the output to the pi is working.
  Requires an analog temperature sensor that is included in an Arduino starter
  kit */

const int tempPin = A0;

const float baselineTemp = 20.0;

#include <serial.h>
Serial mySerial;
PrintWriter output;

void setup() {
  mySerial = new Serial( this, Serial.list()[0], 9600 );
  output = createWriter( "data.txt" );
}

void loop() {
  int temp = analogRead(tempPin);
  temp = (temp / 1024.0) * 5.0;
  temp = (temp - 0.5) * 100;
  Serial.println(temp);
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
