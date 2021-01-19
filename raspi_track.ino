#include <AFMotor.h>

AF_DCMotor motor1(1); 
AF_DCMotor motor2(2);

int income[2];
char i;
int cX,cY;

void baca_raspi()
{
 if (Serial.available() > 0)
   {
        // read the incoming byte:
        for (i=0;i<2;i++)
        {
          income[i] = Serial.parseInt();
          cX=income[0];
          cY=income[1];
          
          Serial.print("posX = "); Serial.print(cX); Serial.print("\t");
          Serial.print("posY = "); Serial.print(cY); Serial.print("\n");        }
              
   }

    else
    {
      Stop();
      Serial.println("Not detected");
    }
}


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
  motor1.setSpeed(200); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(200); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor clockwise
}

void left()
{ 
  motor1.setSpeed(200); 
  motor1.run(BACKWARD); //rotate the motor counterclockwise
  motor2.setSpeed(200); 
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
  Serial.begin(9600);

}

void loop() 
{
  baca_raspi();
  
  if (cX>400)
  {
    right();
//	  
//	  if (cY<200)
//	  {
//		  forward();
//	  }
//	  
//	  else if(cY>350)
//	  {
//		  back;
//	  }
//	  
//	  else
//	  {
//		  Stop();
//	  }
  	  
  }
  
  else if(cX<200)
  {
    left(); 
//	  if (cY<150)
//	  {
//		  forward();
//	  }
//	  
//	  else if(cY>300)
//	  {
//		  back;
//	  }
//	  
//	  else
//	  {
//		  Stop();
//	  }
  }
  
  else
  {
	  Stop();
  }
}
