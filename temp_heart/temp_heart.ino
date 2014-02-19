#include <Ethernet.h>  // must be included to use IoTkit
#include <IoTkit.h>    // include IoTkit.h to use the Intel IoT Kit
#include <math.h>

IoTkit iotkit;

// heartbeat consts
int ledPin = 13;
int sensorPin = 1;
double alpha = 0.75;
int period = 20;
double change = 0.0;

// bodytemp consts
int pin = 0;
double bodytemp;

//for gps
unsigned char buffer[64];                   // buffer array for data recieve over serial port
int count=0; 
int longitude = 0, latitude = 0, digit;

void setup ()
{
  pinMode (ledPin, OUTPUT);
  Serial.begin (115200);  
  Serial1.begin(9600);                 // the SoftSerial baud rate
  iotkit.begin();
  iotkit.registerMetric("heartbeat", "float", "BPS");
  iotkit.registerMetric("bodytemp", "float", "Fahrenheit");
  iotkit.registerMetric("lon", "int", "Degrees");
  iotkit.registerMetric("lat", "int", "Degrees");
  for (int j = 0; j < 400; j++) {getChar();}
}

void loop ()
{
  static double oldValue = 0;
  static double oldChange = 0;
  int rawValue = analogRead (sensorPin);
  double value = alpha * oldValue + (1 - alpha) * rawValue;
     Serial.print (rawValue);
  Serial.print (", ");
  Serial.println (value);
  oldValue = value;
  iotkit.send("heartbeat", value);

  bodytemp = Thermister(analogRead(pin));
  Serial.print(bodytemp); // display Fahrenheit
  Serial.println("f");
  iotkit.send("bodytemp", bodytemp);
 if (count == 10) {
  while (true) {
    
   //if (getChar() != '\n') continue;
  
//    if (getChar() != '$'){ continue;}

    if (getChar() != 'G') continue;

    if (getChar() != 'P') continue;
    if (getChar() != 'G') continue;
    if (getChar() != 'L') continue;
    if (getChar() != 'L') continue;
    if (getChar() != ',') continue;
    
    for (digit = getChar(), latitude = 0; digit != '.'; digit = getChar()) {
      latitude = 10*latitude + digit - '0';
    }
    for (int i = 0; i < 8; i++) getChar();
    for (digit = getChar(), longitude = 0; digit != '.'; digit = getChar()) {
      longitude = 10*longitude + digit - '0';
    } 
    iotkit.send("lon", longitude);
  iotkit.send("lat", latitude);
  Serial.println("data below");
  Serial.println(longitude);
  Serial.println(latitude);
  longitude = 0;
  latitude = 0;

  break;
  
  }count = 0;}
  count++;
  
  
  
  
  
  
  
//  //delay(1000);
//  if (Serial1.available())                     // if date is comming from softwareserial port ==> data is comming from Serial1 shield
//  {
//    while(Serial1.available())               // reading data into char array
//    {
//      buffer[count++]=Serial1.read();      // writing data into array
//      if(count == 64)break;
//    }
//    Serial.write(buffer,count);                 // if no data transmission ends, write buffer to hardware serial port
//    clearBufferArray();                         // call clearBufferArray function to clear the storaged data from the array
//    count = 0;                                  // set counter of while loop to zero
//
//
//  }
//  if (Serial.available())                 // if data is available on hardwareserial port ==> data is comming from PC or notebook
//    Serial1.write(Serial.read());        // write it to the SoftSerial shield
delay(400);
}

double Thermister (int RawADC) {
  double Temp;
  Temp = log (((10240000/RawADC) - 10000));
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp)) * Temp);
  Temp = Temp - 273.15; // Convert Kelvin to Celcius
  return Temp*(9/5) + 32 + 35;
}
void clearBufferArray()                     // function to clear buffer array
{
  for (int i=0; i<count;i++)
  { 
    buffer[i]=NULL;
  }                      // clear all index of array with command NULL
}

char getChar() {

if (Serial1.available()) {
  return Serial1.read();

}
}

