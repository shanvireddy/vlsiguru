#include <dht.h>

//#include "DHT.h"
#define dht_apin A0 // Analog Pin sensor is connected to
int ledpin=13;
dht DHT;
 
void setup()
{
  pinMode(ledpin,OUTPUT);
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(500);//Wait before accessing Sensor
 
}//end "setup()"
 
void loop()
{
  //Start of Program 
 
    DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("  %   ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("  C  ");   
    delay(500);//Wait 5 seconds before accessing sensor again.
    if(DHT.temperature>=40)
    {
      digitalWrite(ledpin,HIGH);
      delay(5000);
    }
    else
    {
      digitalWrite(ledpin,LOW);
    }
  //Fastest should be once every two seconds.
 
}// end loop() void setup() {
  // put your setup code here, to run once:




