
unsigned char buffer[64];                   // buffer array for data recieve over serial port
int count=0;     // counter for buffer array
int index = 0;

void setup()
{
  Serial1.begin(9600);                 // the SoftSerial baud rate
  Serial.begin(115200);                     // the Serial port of Arduino baud rate.
}

void loop()
{
  while (1) {
    int longitude = 0, latitude = 0;
    if (getChar() != '\n') continue;
    if (getChar() != '$') continue;
    if (getChar() != 'G') continue;
    if (getChar() != 'P') continue;
    if (getChar() != 'G') continue;
    if (getChar() != 'L') continue;
    if (getChar() != 'L') continue;
    if (getChar() != ',') continue;
    
    
    
    
    
  }
}
char getChar() {
while (1) {
if (Serial1.available()) {
  return Serial1.read();
}
}
}
//void extract() {
//  if (Serial1.available())                     // if date is comming from softwareserial port ==> data is comming from Serial1 shield
//  {
//    while(Serial1.available())               // reading data into char array
//    {
//      buffer[count++]=Serial1.read();      // writing data into array
//      if(count == 64)break;
//    }
//
//    while(True) {
//      if (buffer[index] == '\n') {
//        if (buffer[index+1] == '$') {
//          if (buffer[index+2] == 'G') {
//            if (buffer[index+3] == 'P') {
//              if (buffer[index+4] == 'G') {
//                if (buffer[index+5] == 'L') {
//                  if (buffer[index+6] == 'L') {
//                    index = index + 8;
//                    longitude = getFloat();
//                    while (buffer[index] != ',') {
//                      index++;
//                    }
//                    
//                    }
//                  }
//                }
//              }
//            }
//          }
//        }
//
//        index++;
//
//    }
//
//  }
//  
//}
float getFloat(char* p) {

  int numOfSym = 0;
  float num = 0; 
  for (; *p != '.'; ++p) num = 10*num + *p - '0'; 

}
//void clearBufferArray()                     // function to clear buffer array
//{
//  for (int i=0; i<count;i++)
//  { 
//    buffer[i]=NULL;
//  }                      // clear all index of array with command NULL
//}



















