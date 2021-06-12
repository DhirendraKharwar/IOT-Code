/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on NodeMCU.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right NodeMCU module
  in the Tools -> Board menu!

  For advanced settings please follow ESP examples :
   - ESP8266_Standalone_Manual_IP.ino
   - ESP8266_Standalone_SmartConfig.ino
   - ESP8266_Standalone_SSL.ino

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).

char auth[] = "X9Iwhrz3HyBEP2TGuNVVPXgPG0YzeJox";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "DDDDESKTOP";
char pass[] = "90768461211";
int flag =0;
int flag2 =0;

void NotifyThingsMove()
{
  int ThingsMove = digitalRead(D1);
  if(ThingsMove ==1 && flag == 0)
  {
    digitalWrite(4,HIGH);
    Serial.println("Hello Dhirendra Someone moved under my Area");
    Blynk.notify("Alert: Hello Dhirendra! Someone moved under my Area");
    flag=1;
  }
  else if(ThingsMove ==0)
  {
    flag =0;
  }
}

void NotityThingCrossingFromSensor()
{
    int ThingCrossing = digitalRead(D2);
    if(ThingCrossing ==1 && flag2 == 0)
    {
      //digitalWrite(4,HIGH);
      Serial.println("Hello Dhirendra Someone entered in the Room");
      Blynk.notify("Alert:Hello! Someone Entered in the room");
      flag2=1;
    }
  else if(ThingCrossing ==0)
  {
    flag2 =0;
  }
}

void LightDetectingRegister()
{
  
  int LDR = analogRead(A0);
  if(LDR >440)
  {
    digitalWrite(2,HIGH);
  }
  else
  {
    digitalWrite(2,LOW);
  }
  Serial.print("LDR Value = ");
  Serial.println(LDR); 
  
  Blynk.virtualWrite(V0, LDR);
}

void Temperature()
{
    int temp = analogRead(D3);
    Serial.print("Temperature Value = ");
    Serial.println(temp); 
    Blynk.virtualWrite(V0, temp);
}
  



void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(D1,INPUT_PULLUP);
  pinMode(D2,INPUT_PULLUP);
  pinMode(D3,INPUT_PULLUP);
  pinMode(2,OUTPUT);
  pinMode(A0,INPUT);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L,NotifyThingsMove);
  timer.setInterval(1000L,NotityThingCrossingFromSensor);
  timer.setInterval(1000L,LightDetectingRegister);
  timer.setInterval(1000L,Temperature);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
  timer.run();
}