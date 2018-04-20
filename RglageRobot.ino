
 
 #include <Wire.h> 
 #include <LiquidCrystal_I2C.h>
 //LiquidCrystal_I2C lcd(0x27, 20, 4);
 LiquidCrystal_I2C lcd(0x3F,20,4);
 
 #include <Servo.h>
 Servo Servo3;  
 Servo Servo5;  
 Servo Servo6;  
 Servo Servo9;  


 const int Servo3_SensorPin = A0; 
 const int Servo5_SensorPin = A1; 
 const int Servo6_SensorPin = A2; 
 const int Servo9_SensorPin = A3; 

 int Servo3_SensorValue = 0;         // the sensor value
 int Servo5_SensorValue = 0;
 int Servo6_SensorValue = 0;
 int Servo9_SensorValue = 0;
 
 int Servo3_SensorLastValue = 0;         // the sensor value
 int Servo5_SensorLastValue = 0;
 int Servo6_SensorLastValue = 0;
 int Servo9_SensorLastValue = 0; 
 
 int sensorMax = 1023;        // minimum sensor value
 int sensorMin = 0;           // maximum sensor value
 int servoMax = 180;        // minimum sensor value
 int servoMin = 0;           // maximum sensor value 

 int temp = 0;

void setup() {
  // put your setup code here, to run once:
   Servo3.attach(3); 
   Servo5.attach(5); 
   Servo6.attach(6); 
   Servo9.attach(9);  
   Serial.begin (9600);

   lcd.init(); 


}

void loop() {
  // put your main code here, to run repeatedly:
  
  temp = 0;
  while ( temp == 0 )
  {

    Servo3_SensorValue = map(analogRead(Servo3_SensorPin), sensorMin, sensorMax, servoMin, servoMax);
    if (   ( Servo3_SensorValue > ( Servo3_SensorLastValue + 2 ) ) || ( Servo3_SensorValue < ( Servo3_SensorLastValue - 2 ) ) )
    {
      Servo3.write(Servo3_SensorValue);
      Serial.print("3, ");
      Serial.print(Servo3_SensorValue);
      Serial.print(", ");
      Servo3_SensorLastValue = Servo3_SensorValue;
    }
    delay(20);
    temp = 1;
  }
  
  temp = 0;
  while ( temp == 0 )
  {
    Servo5_SensorValue = map(analogRead(Servo5_SensorPin), sensorMin, sensorMax, servoMin, servoMax);
    if (  ( Servo5_SensorValue > ( Servo5_SensorLastValue + 3 ) ) || ( Servo5_SensorValue < ( Servo5_SensorLastValue - 3 ) ) )
    {
      Servo5.write(Servo5_SensorValue);
      Serial.print("5, ");
      Serial.print(Servo5_SensorValue);
      Serial.print(", ");
      Servo5_SensorLastValue = Servo5_SensorValue;
    }
    delay(20);
    temp = 1;
  }
    
  temp = 0;
  while ( temp == 0 )
  {
    Servo6_SensorValue = map(analogRead(Servo6_SensorPin), sensorMin, sensorMax, servoMax, servoMin);
    if (  ( Servo6_SensorValue > ( Servo6_SensorLastValue + 3 ) ) || ( Servo6_SensorValue < ( Servo6_SensorLastValue - 3 ) ) )
    {
      Servo6.write(Servo6_SensorValue);
      Serial.print("6, ");
      Serial.print(Servo6_SensorValue);
      Serial.print(", ");
      Servo6_SensorLastValue = Servo6_SensorValue;
    }
    delay(20);
    temp = 1;
  }
  
  temp = 0;
  while ( temp == 0 )
  {
    Servo9_SensorValue = map(analogRead(Servo9_SensorPin), sensorMin, sensorMax, servoMin, servoMax);
    if (  ( Servo9_SensorValue > ( Servo9_SensorLastValue + 2 ) ) || ( Servo9_SensorValue < ( Servo9_SensorLastValue - 2 ) ) )
    {
      Servo9.write(Servo9_SensorValue);
      Serial.print("9, ");
      Serial.print(Servo9_SensorValue);
      Serial.print(", ");
      Servo9_SensorLastValue = Servo9_SensorValue;
    }
    delay(20);
    temp = 1;
  }

  
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("(3)=");
    if ( Servo3_SensorValue < 100 )
  {
    lcd.setCursor(4, 0);
    lcd.print(" ");
    lcd.setCursor(5, 0);
    lcd.print(Servo3_SensorValue);
  }
  else
  {
    lcd.setCursor(4, 0);
    lcd.print(Servo3_SensorValue);
  }

  //----------
  lcd.setCursor(8, 0);
  lcd.print("(5)=");
    if ( Servo5_SensorValue < 100 )
  {
    lcd.setCursor(12, 0);
    lcd.print(" ");
    lcd.setCursor(13, 0);
    lcd.print(Servo5_SensorValue);
  }
  else
  {
    lcd.setCursor(12, 0);
    lcd.print(Servo5_SensorValue);
  }

  //----------
  lcd.setCursor(0, 1);
  lcd.print("(6)=");
    if ( Servo6_SensorValue < 100 )
  {
    lcd.setCursor(4, 1);
    lcd.print(" ");
    lcd.setCursor(5, 1);
    lcd.print(Servo6_SensorValue);
  }
  else
  {
    lcd.setCursor(4, 1);
    lcd.print(Servo6_SensorValue);
  }

  //----------
  lcd.setCursor(8, 1);
  lcd.print("(9)=");
    if ( Servo9_SensorValue < 100 )
  {
    lcd.setCursor(12, 1);
    lcd.print(" ");
    lcd.setCursor(13, 1);
    lcd.print(Servo9_SensorValue);
  }
  else
  {
    lcd.setCursor(12, 1);
    lcd.print(Servo9_SensorValue);
  }
  delay(1);

}
