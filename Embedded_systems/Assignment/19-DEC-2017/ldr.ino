// program to read the analog values from the LDR sensor 
// set the led based on the threshold reading of LDR 


int ledpin=13;
int sensorPin = A0; // select the input pin for LDR
int sensorValue = 0; // variable to store the value coming from the sensor

void setup() 
{
    Serial.begin(9600); //sets serial port for communication
    pinMode(ledpin,OUTPUT);
}

void loop()
{
   sensorValue = analogRead(sensorPin); // read the value from the sensor
   Serial.println(sensorValue); //prints the values coming from the sensor on the screen
   delay(100);
   if(sensorValue<=600)
   {
      digitalWrite(ledpin,HIGH);
      Serial.println("LDR is DARK, LED is ON");
   }
   else
   {
      digitalWrite(ledpin,LOW);
      Serial.println("LED is OFF");
   }
}

