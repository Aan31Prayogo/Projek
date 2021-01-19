#include <Servo.h> 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

Servo servo1;
Servo servo2;
char led1=5;
char led2=6;
char led3=7;
char led4=8;
char IR1=2;
char IR2=3;
char buzzer=4;
bool IR1state;
bool IR2state;

void setup() 
{
   Serial.begin(9600);
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  lcd.noBlink();
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT); 
  
  servo1.attach(9);
  servo2.attach(10);

 //attachInterrupt(digitalPinToInterrupt(IR1), readIR1, LOW);
  //attachInterrupt(digitalPinToInterrupt(IR2), readIR2, LOW);
  lcd.setCursor(0,0);
  lcd.print("Touchless System"); tit(1); 
  delay(2000);
  lcd.setCursor(0,1);
  lcd.print("By Aan Prayogo"); tit(2);  servo1.write(0);  servo2.write(0);
  delay(2000);
    lcd.setCursor(0,0);
  lcd.print("                        ");
      lcd.setCursor(0,1);
  lcd.print("                        ");
  
  lcd.setCursor(0,0);
  lcd.print("Keran :");
  lcd.setCursor(0,1);
  lcd.print("Sabun :");

}

void loop() 
{ 
 
 run_sis();

}


void run_sis()
{
   IR1state= digitalRead(IR1);
  IR2state= digitalRead(IR2);

  Serial.print("IR1 State ="); Serial.print(IR1state); Serial.print("\t");
  Serial.print("IR2 State ="); Serial.println(IR2state);

  if (IR1state == 1 && IR2state ==1)
  { 
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,LOW);
  

     lcd.setCursor(8,0);
     lcd.print("OFF");
     lcd.setCursor(8,1);
     lcd.print("OFF");
    
  }

  else if (IR1state == 0 && IR2state ==1)
    {
      digitalWrite(led1,LOW);
      digitalWrite(led2,HIGH);
       digitalWrite(led3,HIGH);
      digitalWrite(led4,LOW);
  

    lcd.setCursor(8,0);    
    lcd.print("      ");
    lcd.setCursor(8,0);
    lcd.print("ON");
    lcd.setCursor(8,1);
    lcd.print("OFF");
    beep();

       servo2.write(150);
      delay(5000);
      servo2.write(0);
      delay(300);
      tit(2); 
    
    
  }

  else if (IR1state == 1 && IR2state ==0)
  {
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,HIGH);
  

     lcd.setCursor(8,0); 
     lcd.print("OFF");
      lcd.setCursor(8,1);
      lcd.print("     ");
     lcd.setCursor(8,1);
     lcd.print("ON");
      beep();

      servo1.write(120);
      delay(600);
      servo1.write(0);
      delay(300);
      tit(2); 
      
  }

  else 
  {
    
    digitalWrite(led1,HIGH); tit(1);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);

  }
}
void tit(char o)
{
  for (char i=0; i<o;i++)
  {
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
    delay(50);
  }
}

void beep()
{
  digitalWrite(buzzer,HIGH);
    delay(200);
    digitalWrite(buzzer,LOW);
    delay(50);
}
