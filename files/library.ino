#include <dht.h>
#define dht_apin D2 // Analog Pin sensor is connected to
dht DHT;
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
String tw="";
int t1=0;
int t2=0;
int at1=0;
int at2=0;
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "<AUTH TOKEN>";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "<SSID>";
char pass[] = "<PASSWORD>";
void setup(){
 
  Serial.begin(9600);
 pinMode(D2,INPUT);
  delay(500);//Delay to let system boot
 
  Serial.println("DHT11 Humidity & temperature Sensor");
 
  delay(1000);//Wait before accessing Sensor
   Blynk.begin(auth, ssid, pass);
 
}//end "setup()"
 
void loop(){
   Blynk.run();
  //Start of Program 
 
  DHT.read11(dht_apin);
 
    Serial.print("Current humidity = ");
 
    Serial.print(DHT.humidity);
 
    Serial.print("%  ");
 
    Serial.print("temperature = ");
 
    Serial.print(DHT.temperature); 
 
    Serial.println("C  ");
    Serial.println(D3);
    if(digitalRead(D3)==0)
    {
    Blynk.tweet("Hello This is AI");
    delay(10000);
    }
 if(t1==1)
 {
  at1=millis();
 }
  //Wait 3 seconds before accessing sensor again.
  else if(t1==60)
  {
  Blynk.virtualWrite(V1,DHT.humidity);
  Blynk.virtualWrite(V2,DHT.temperature);
  t1=0;
  
  Serial.print(millis()-at1);
  Serial.println("  t1 ---");
  
  }
 if(t2==1)
 {
  at2=millis();
 }
  else if(t2==200)
  {
    tw="Hello";
  tw="Temperature is ";
  tw=tw+DHT.temperature;
  tw=tw+" Degree Celcius & Humidity is ";
  tw=tw+DHT.humidity;
  tw=tw+" %";
  Blynk.tweet(tw);
  tw="";
  t2=0;
  Serial.print(millis()-at2);
  Serial.println("  t2 ----------");
  }
  
  delay(1);
  
  t1++;
  t2++;
  //Fastest should be once every two seconds.
 
}// end loop() 
