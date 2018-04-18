
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
 
 int sensorMax = 1023;        // minimum sensor value
 int sensorMin = 0;           // maximum sensor value
 int servoMax = 180;        // minimum sensor value
 int servoMin = 0;           // maximum sensor value 

 int temp = 0;
 int tempa = 0;
 int automate [] = {3, 88, 3, 84, 3, 79, 3, 73, 3, 67, 3, 64, 3, 60, 3, 53, 3, 49, 3, 46, 3, 43, 3, 40, 5, 72, 5, 77, 5, 82, 5, 89, 5, 94, 5, 98, 5, 103, 5, 107, 9, 3, 9, 8, 9, 11, 9, 16, 9, 20, 9, 26, 9, 33, 9, 42, 9, 50, 9, 56, 9, 60, 9, 64, 9, 67, 5, 112, 5, 118, 5, 123, 5, 127, 5, 131, 6, 172, 6, 168, 6, 162, 6, 158, 6, 152, 6, 147, 6, 140, 6, 134, 6, 130, 5, 135, 5, 140, 5, 144, 9, 64, 9, 58, 9, 52, 9, 46, 9, 40, 9, 34, 9, 27, 9, 20, 9, 12, 9, 7, 9, 0, 3, 37, 6, 124, 6, 119, 6, 115, 6, 111, 5, 148, 5, 155, 5, 161, 5, 166, 5, 160, 5, 156, 5, 151, 5, 147, 5, 141, 5, 134, 5, 129, 5, 125, 5, 120, 5, 114, 5, 110, 5, 105, 3, 42, 3, 39, 6, 118, 6, 124, 6, 129, 6, 133, 6, 137, 6, 142, 3, 36, 3, 39, 6, 151, 6, 155, 5, 101, 5, 97, 5, 92, 6, 161, 6, 168, 5, 88, 5, 83, 5, 78, 5, 71, 5, 67, 3, 44, 3, 47, 3, 50, 3, 55, 3, 59, 6, 172, 3, 62, 3, 68, 3, 73, 3, 76, 6, 167, 3, 79, 3, 84, 3, 87, 3, 91, 3, 96, 3, 99, 3, 103, 3, 108, 3, 112, 6, 172, 3, 115, 3, 119, 3, 123, 3, 127, 3, 130, 3, 133, 3, 136, 6, 168, 3, 141, 3, 146, 3, 150, 5, 63, 5, 57, 3, 153, 3, 149, 5, 62, 5, 68, 5, 74, 5, 80, 5, 86, 5, 90, 5, 94, 5, 99, 6, 162, 6, 157, 5, 103, 5, 108, 5, 113, 5, 117, 6, 152, 6, 147, 5, 121, 5, 125, 5, 129, 6, 142, 6, 138, 5, 133, 5, 142, 5, 146, 5, 142, 5, 146, 9, 5, 9, 0, 9, 3, 9, 9, 9, 14, 9, 20, 9, 25, 9, 31, 9, 36, 9, 41, 9, 46, 9, 52, 9, 57, 9, 61, 9, 64, 9, 67, 9, 70, 6, 132, 6, 126, 5, 142, 6, 122, 5, 146, 5, 151, 5, 156, 5, 160, 5, 154, 5, 149, 3, 153, 5, 143, 3, 148, 9, 67, 5, 137, 5, 130, 5, 126, 5, 121, 5, 116, 9, 70, 3, 151, 6, 118, 6, 114, 3, 148, 6, 108, 3, 151, 5, 121, 5, 126, 5, 130, 5, 124, 5, 118, 5, 112, 5, 108, 5, 101, 5, 95, 3, 147, 3, 150, 6, 112, 6, 117, 6, 122, 6, 126, 6, 130, 6, 134, 6, 138, 6, 144, 6, 148, 6, 152, 6, 158, 6, 162, 3, 147, 3, 151, 5, 89, 5, 85, 5, 79, 5, 74, 5, 67, 5, 63, 5, 59, 6, 168, 6, 173, 3, 148, 3, 143, 3, 139, 3, 135, 3, 130, 3, 126, 3, 122, 3, 118, 3, 114, 3, 109, 6, 177, 3, 104, 3, 100, 3, 96, 3, 93, 6, 171, 9, 66, 9, 63, 9, 59, 9, 55, 9, 51, 9, 46, 9, 40, 9, 35, 6, 177, 9, 29, 9, 23, 9, 18, 9, 13, 9, 5, 9, 1, 6, 173, 9, 4, 9, 0, 6, 177, 6, 173, 6, 178, 6, 174, 9, 5, 9, 0 };

 
 int avancement = 0;

void setup() {
  // put your setup code here, to run once:
   Servo3.attach(3); 
   
   Servo5.attach(5); 
   
   Servo6.attach(6); 
  
   Servo9.attach(9);
   
   Serial.begin (9600);


}

void loop() {
  // put your main code here, to run repeatedly:

  while ( tempa == 0 )
  {
   Servo3_SensorValue = map(analogRead(Servo3_SensorPin), sensorMin, sensorMax, servoMin, servoMax);
   Servo3.write(Servo3_SensorValue);
   delay(100);

   Servo5_SensorValue = map(analogRead(Servo5_SensorPin), sensorMin, sensorMax, servoMin, servoMax);
   Servo5.write(Servo5_SensorValue);
   delay(100);

   Servo6_SensorValue = map(analogRead(Servo6_SensorPin), sensorMin, sensorMax, servoMax, servoMin);
   Servo6.write(Servo6_SensorValue);
   delay(100);

   Servo9_SensorValue = map(analogRead(Servo9_SensorPin), sensorMin, sensorMax, servoMin, servoMax);
   Servo9.write(Servo9_SensorValue);
   delay(3000);
   tempa = 1;
  }
  
  temp = 0;
  if ( automate[avancement] == 3 )
  {
    while ( temp == 0 )
    {
      //Servo3_SensorValue = map(analogRead(Servo3_SensorPin), sensorMin, sensorMax, servoMin, servoMax);
      Servo3.write(automate[avancement + 1]);
      Serial.print("3, ");
      Serial.print(Servo3_SensorValue);
      Serial.print(", ");
      delay(100);
      temp = 1;
      avancement+=2;
    }
  }
  
  temp = 0;
  if ( automate[avancement] == 5 )
  {
    while ( temp == 0 )
    {
      //Servo5_SensorValue = map(analogRead(Servo5_SensorPin), sensorMin, sensorMax, servoMin, servoMax);
      Servo5.write(automate[avancement + 1]);
      Serial.print("5, ");
      Serial.print(Servo5_SensorValue);
      Serial.print(", ");
      delay(100);
      temp = 1;
      avancement+=2;
    }
  }
    
  temp = 0;
  if ( automate[avancement] == 6 )
  {
    while ( temp == 0 )
    {
      //Servo6_SensorValue = map(analogRead(Servo6_SensorPin), sensorMin, sensorMax, servoMax, servoMin);
      Servo6.write(automate[avancement + 1]);
      Serial.print("6, ");
      Serial.print(Servo6_SensorValue);
      Serial.print(", ");
      delay(100);
      temp = 1;
      avancement+=2;
    }
  }
  
  temp = 0;
  if ( automate[avancement] == 9 )
  {
    while ( temp == 0 )
    {
      //Servo9_SensorValue = map(analogRead(Servo9_SensorPin), sensorMin, sensorMax, servoMin, servoMax);
      Servo9.write(automate[avancement + 1]);
      Serial.print("9, ");
      Serial.print(Servo9_SensorValue);
      Serial.print(", ");
      delay(100);
      temp = 1;
      avancement+=2;
    }
  }

}
