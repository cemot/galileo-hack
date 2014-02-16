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

void setup ()
{
  pinMode (ledPin, OUTPUT);
  Serial.begin (115200);  
  iotkit.begin();
  iotkit.registerMetric("heartbeat", "float", "BPS");
  iotkit.registerMetric("bodytemp", "float", "Fahrenheit");
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
  //delay(1000);
  delay (1000);
}

double Thermister (int RawADC) {
  double Temp;
  Temp = log (((10240000/RawADC) - 10000));
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp)) * Temp);
  Temp = Temp - 273.15; // Convert Kelvin to Celcius
  return Temp*(9/5) + 32 + 35;
}
