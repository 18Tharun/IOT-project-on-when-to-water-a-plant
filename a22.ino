#include <SoftwareSerial.h>

SoftwareSerial BTSerial =  SoftwareSerial(0,1);

int sensor_pin =A0;
void setup() {
  // put your setup code here, to run once:
  BTSerial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 float moisture_percentage;
 int flag=0;
  int sensor_analog;
  sensor_analog = analogRead(sensor_pin);
  moisture_percentage = ( 100 - ( (sensor_analog/1023.00) * 100 ) );
  Serial.print("Moisture Percentage = ");
  Serial.print(moisture_percentage);
  Serial.print("%\n\n");
  delay(1000);

  if(moisture_percentage<25){digitalWrite(13,HIGH);
    delay(1000);
    BTSerial.println(moisture_percentage);
    delay(1000);
    BTSerial.print(";");
    delay(1000);
    BTSerial.print("DRY");
    delay(1000);
    BTSerial.print(";");
    delay(1000);
    BTSerial.print("WATER IMMEDIATELY");
    delay(1000);
   /* BTSerial.print("Water plant");
    //BTSerial.print(moisture_percentage);
    delay(1000);*/
    }else if(moisture_percentage>25 && moisture_percentage<50){
      digitalWrite(13,HIGH);
      BTSerial.println(moisture_percentage);
    delay(1000);
    BTSerial.print(";");
    delay(1000);
    BTSerial.print("LOWWET");
    delay(1000);
    BTSerial.print(";");
    delay(1000);
    BTSerial.print("WET");
    delay(1000);
    //BTSerial.print("DON'T Water plant");
   // delay(1000);
      }else if(moisture_percentage>50 && moisture_percentage<75){digitalWrite(13,LOW);
      delay(1000);
      BTSerial.println(moisture_percentage);
    delay(1000);
    BTSerial.print(";");
    delay(1000);
    BTSerial.print("MODERATEWET");
    delay(1000);
    BTSerial.print(";");
    delay(1000);
    BTSerial.print("WET");
        
     }else if(moisture_percentage>75){digitalWrite(13,LOW);
      delay(1000);
      BTSerial.println(moisture_percentage);
    delay(1000);
    BTSerial.print(";");
    delay(1000);
    BTSerial.print("HIGHWET");
    delay(1000);
    BTSerial.print(";");
    delay(1000);
    BTSerial.print("WET");
    delay(1000);
    //BTSerial.print("DON'T Water plant");
   // delay(1000);
      }
    

}
