#include <Servo.h>

Servo servo1;
char command;

void setup()
{
  Serial.begin(9600);
  servo1.attach(9);
  servo1.write(0);
}

void loop()
{
  if (Serial.available()>0)
  {
    command=Serial.read();
    Serial.println(command);
    
    switch(command)
    {
      case 'A':
        servo1.write(180);
       break;
       
       case 'B':
         servo1.write(0);
        break; 
    }
  
  }

}
