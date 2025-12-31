#include "SR04.h"

int trig = 12;
int echo = 11;
int buzzer = 9;

//setup sensor
SR04 sr04 = SR04(echo,trig);
int distance;

void setup() {
   Serial.begin(9600);
   pinMode(buzzer, OUTPUT);

}

void loop() {
   distance = sr04.Distance(); //find the distance of the object
   Serial.print(distance);
   Serial.println("cm");
   delay(1000);

   //if object within 50cm, sound the alarm
   if (distance < 50){
      tone(buzzer, 1000); // Send 1KHz sound signal...
      delay(300);        
      noTone(buzzer);     // Stop sound...

   }
   //if there's no object, keep the buzzer silent
   else{
      noTone(buzzer);
   }

} 
