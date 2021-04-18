#include <AFMotor.h>
#include <Servo.h>

AF_DCMotor motor1(1); 
AF_DCMotor motor2(2);
AF_DCMotor motor3(3); 
AF_DCMotor motor4(4);

char command;
Servo servo1;
Servo servo2;
int angle1=95;
int angle2=90;

void forward()
{
  motor1.setSpeed(180); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(180); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(180); //Define maximum velocity
  motor3.run(FORWARD); //rotate the motor clockwise
  motor4.setSpeed(180); //Define maximum velocity
  motor4.run(FORWARD); //rotate the motor clockwise
}

void back()
{
  motor1.setSpeed(180); 
  motor1.run(BACKWARD); //rotate the motor counterclockwise
  motor2.setSpeed(180); 
  motor2.run(BACKWARD); //rotate the motor counterclockwise
  motor3.setSpeed(100); 
  motor3.run(BACKWARD); //rotate the motor counterclockwise
  motor4.setSpeed(180); 
  motor4.run(BACKWARD); //rotate the motor counterclockwise
}

void right()
{
  motor1.setSpeed(150); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(150); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor clockwise
  motor3.setSpeed(150); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor clockwise
  motor4.setSpeed(150); //Define maximum velocity
  motor4.run(FORWARD); //rotate the motor clockwise
}

void left()
{ 
  motor1.setSpeed(150); 
  motor1.run(BACKWARD); //rotate the motor counterclockwise
  motor2.setSpeed(150); 
  motor2.run(FORWARD); //rotate the motor counterclockwise
  motor3.setSpeed(150); 
  motor3.run(FORWARD); //rotate the motor counterclockwise
  motor4.setSpeed(150); 
  motor4.run(BACKWARD); //rotate the motor counterclockwise
}

void Stop()
{
  motor1.setSpeed(0);
  motor1.run(RELEASE); //turn motor1 off
  motor2.setSpeed(0);
  motor2.run(RELEASE); //turn motor2 off
  motor3.setSpeed(0);
  motor3.run(RELEASE); //turn motor1 off
  motor4.setSpeed(0);
  motor4.run(RELEASE); //turn motor2 off
}

void Pan_right(){
  //angle1=90;
  angle1+=3;
  servo1.write(angle1);
  if (angle1 >180){
    servo1.write(180);
    angle1=180;
  }
  angle1=angle1;
  Serial.print("angle1 =");
  Serial.println(angle1);
  
}

void Pan_left(){
  //angle1=90;
  angle1-=3;
  servo1.write(angle1);
  if (angle1 <0){
    servo1.write(0);
    angle1=0;
  }
  angle1=angle1;
  Serial.print("angle1 =");
  Serial.println(angle1);

}

void Tilt_up(){
  //angle2 =90;
  angle2 +=3;
  servo2.write(angle2);
  if (angle2 >180){
    servo2.write(180);
    angle2=180;
  }
  angle2=angle2;
  Serial.print("angle2 =");
  Serial.println(angle2);
}

void Tilt_down(){
  //angle2= 90;
  angle2 -= 3;
  servo2.write(angle2);
  if (angle2<0){
    servo2.write(0);
    angle2=0;
  }
  angle2=angle2;
  Serial.print("angle2 =");
  Serial.println(angle2);

}

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  servo1.attach(10);
  servo2.attach(9);
  servo1.write(angle1); servo2.write(angle2);
  Serial.println("program Starting!!");
  Serial.println("#####################################");
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

        case 'U':
          Tilt_down();
        break;

        case 'D':
          Tilt_up();
        break;

        case 'M':
          Pan_left();
        break;

        case 'N':
          Pan_right();
        break;
      }
    }
  
}  
