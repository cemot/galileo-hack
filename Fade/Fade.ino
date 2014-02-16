/*
 Fade
 
 This example shows how to fade an LED on pin 9
 using the analogWrite() function.
 
 This example code is in the public domain.
 */
int heart = 3;
int led = 13;           // the pin that the LED is attached to
double alpha = 0.75;
int period = 20;
double change = 0.0;

// the setup routine runs once when you press reset:
void setup()  { 
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  Serial.begin(115200);
} 

// the loop routine runs over and over again forever:
void loop()  { 
  // // if (digitalRead(buttonpin) != HIGH) {
  // //   digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  // //   //delay(100);               // wait for a second
  // //       // turn the LED off by making the voltage LOW
  // //   //delay(100);
  // // } else{
  // //   digitalWrite(led, LOW);
  // // }
  // static double oldValue = 0;
  // static double oldChange = 0;
  // int rawValue = analogRead (heart);
  // double value = alpha * oldValue + (1 - alpha) * rawValue;
  // Serial.print (rawValue);
  // Serial.print (",");
  // Serial.println (value);
  // oldValue = value;
  // delay (period);
Serial.println(analogRead(heart));


}


