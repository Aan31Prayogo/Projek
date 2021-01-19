int income[2];
char i;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
   if (Serial.available() > 0)
   {
        // read the incoming byte:
        for (i=0;i<2;i++)
        {
          income[i] = Serial.parseInt();
          int cX=income[0];
          int cY=income[1];
          
          Serial.print("posX = "); Serial.print(cX); Serial.print("\t");
          Serial.print("posY = "); Serial.print(cY); Serial.print("\n");        }
              
  
   }
}
