#include <AFMotor.h>

AF_DCMotor motor1(1); 
AF_DCMotor motor2(2);

char command;
int errorX;
int errorY;


void forward()
{
  motor1.setSpeed(120); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(200); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
}

void full()
{
  motor1.setSpeed(175); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
}

void back()
{
  motor1.setSpeed(100); 
  motor1.run(BACKWARD); //rotate the motor counterclockwise
  motor2.setSpeed(180); 
  motor2.run(BACKWARD); //rotate the motor counterclockwise
}

void right()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor clockwise
}

void left()
{ 
  motor1.setSpeed(255); 
  motor1.run(BACKWARD); //rotate the motor counterclockwise
  motor2.setSpeed(255); 
  motor2.run(FORWARD); //rotate the motor counterclockwise
}

void Stop()
{
  motor1.setSpeed(0);
  motor2.run(RELEASE); //turn motor1 off
  motor2.setSpeed(0);
  motor2.run(RELEASE); //turn motor2 off
}


void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available()>0)
    {
      command=Serial.read();
      Serial.println(command);
  
      switch(command)
      {
        case 'F':
          forward();
        break;

        case 'B':
          back();
        break;

        case 'L':
          left();
        break;

        case 'R':
          right();
        break;

        case 'S':
           Stop();
        break;
      }
    }



}
